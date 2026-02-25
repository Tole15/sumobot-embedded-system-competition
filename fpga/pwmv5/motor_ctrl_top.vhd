-- motor_ctrl_top.vhd
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use work.pwm_pkg.all;

entity motor_ctrl_top is
  port(
    clk_sys    : in  std_logic;  -- Reloj de sistema (~50 MHz)
    reset_sys  : in  std_logic;  -- Reset asíncrono activo en '1'
    -- SPI
    SCLK_in    : in  std_logic;
    MOSI_in    : in  std_logic;
    SS_in      : in  std_logic;
    -- Salidas motor 1
    R_PWM_M1   : out std_logic;
    L_PWM_M1   : out std_logic;
    R_EN_M1    : out std_logic;
    L_EN_M1    : out std_logic;
    -- Salidas motor 2
    R_PWM_M2   : out std_logic;
    L_PWM_M2   : out std_logic;
    R_EN_M2    : out std_logic;
    L_EN_M2    : out std_logic
  );
end entity motor_ctrl_top;

architecture structural of motor_ctrl_top is
  -- Reset sincronizado
  signal rst_sync    : std_logic;
  -- Filtrado de SS_in
  signal SS_t1, SS_t2, SS_filt : std_logic := '1';

  -- SPI
  signal spi_byte    : std_logic_vector(7 downto 0);
  signal ss_rise     : std_logic;

  -- Control y duty
  signal load_pwm    : std_logic;
  signal control_r   : std_logic_vector(7 downto 0);
  signal duty_r      : std_logic_vector(7 downto 0);

  -- Nibbles y PWM crudo
  signal duty_nib_M1 : std_logic_vector(3 downto 0);
  signal duty_nib_M2 : std_logic_vector(3 downto 0);
  signal pwm_raw_M1  : std_logic;
  signal pwm_raw_M2  : std_logic;

  -- Señales de selección
  signal sel_RPWM_M1, sel_LPWM_M1 : std_logic;
  signal sel_RPWM_M2, sel_LPWM_M2 : std_logic;
begin

  ------------------------------------------------------------------------
  -- 1) Reset síncrono: rst_sync = '1' en reset_sys asíncrono, luego se limpia
  rst_sync_proc: process(clk_sys, reset_sys)
  begin
    if reset_sys = '1' then
      rst_sync <= '1';
    elsif rising_edge(clk_sys) then
      rst_sync <= '0';
    end if;
  end process;

  ------------------------------------------------------------------------
  -- 2) Sincronización y filtro de glitches para SS_in
  sync_SS: process(clk_sys)
  begin
    if rising_edge(clk_sys) then
      SS_t1   <= SS_in;
      SS_t2   <= SS_t1;
      -- solo cambio de estado si coinciden dos muestras
      if SS_t1 = SS_t2 then
        SS_filt <= SS_t1;
      end if;
    end if;
  end process;

  ------------------------------------------------------------------------
  -- 3) SPI robusto, usando SS filtrado
  u_spi : entity work.spi_slave_sync
    port map (
      clk_sys   => clk_sys,
      reset_sys => rst_sync,
      SCLK_in   => SCLK_in,
      MOSI_in   => MOSI_in,
      SS_in     => SS_filt,
      data_out  => spi_byte
    );

  ------------------------------------------------------------------------
  -- 4) Detección de flanco de subida de SS_filt
  ss_edge: process(clk_sys)
    variable prev_SS : std_logic := '1';
  begin
    if rising_edge(clk_sys) then
      ss_rise <= '0';
      if (prev_SS = '0' and SS_filt = '1') then
        ss_rise <= '1';
      end if;
      prev_SS := SS_filt;
    end if;
  end process;

  ------------------------------------------------------------------------
  -- 5) FSM de control + generación de load_pwm
  u_fsm : entity work.ctrl_fsm
    port map (
      clk      => clk_sys,
      rst      => rst_sync,
      ss_rise  => ss_rise,
      byte_in  => spi_byte,
      load_pwm => load_pwm,
      control  => control_r,
      duty     => duty_r
    );

  ------------------------------------------------------------------------
  -- 6) Decodificador
  u_dec : entity work.decoder
    port map (
      control  => control_r,
      duty     => duty_r,
      duty_M1  => duty_nib_M1,
      duty_M2  => duty_nib_M2,
      R_PWM_M1 => sel_RPWM_M1, L_PWM_M1 => sel_LPWM_M1,
      R_PWM_M2 => sel_RPWM_M2, L_PWM_M2 => sel_LPWM_M2,
      R_EN_M1  => R_EN_M1,     L_EN_M1  => L_EN_M1,
      R_EN_M2  => R_EN_M2,     L_EN_M2  => L_EN_M2
    );

  ------------------------------------------------------------------------
  -- 7) PWM motor 1 @ 20 kHz (50 MHz/(2499+1))
  u_pwm1 : entity work.pwm_module
    generic map (
      CNT_WIDTH  => 4,
      DUTY_WIDTH => 4,
      DIV_CONST  => 2499
    )
    port map (
      clk   => clk_sys,
      rst   => rst_sync,
      load  => load_pwm,
      ancho => duty_nib_M1,
      pwm   => pwm_raw_M1
    );

  -- PWM motor 2
  u_pwm2 : entity work.pwm_module
    generic map (
      CNT_WIDTH  => 4,
      DUTY_WIDTH => 4,
      DIV_CONST  => 2499
    )
    port map (
      clk   => clk_sys,
      rst   => rst_sync,
      load  => load_pwm,
      ancho => duty_nib_M2,
      pwm   => pwm_raw_M2
    );

  ------------------------------------------------------------------------
  -- 8) Mux final
  R_PWM_M1 <= pwm_raw_M1 when sel_RPWM_M1 = '1' else '0';
  L_PWM_M1 <= pwm_raw_M1 when sel_LPWM_M1 = '1' else '0';
  R_PWM_M2 <= pwm_raw_M2 when sel_RPWM_M2 = '1' else '0';
  L_PWM_M2 <= pwm_raw_M2 when sel_LPWM_M2 = '1' else '0';

end architecture structural;
