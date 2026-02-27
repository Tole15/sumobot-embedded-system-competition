<<<<<<< HEAD
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use work.pwm_pkg.all;

entity motor_ctrl_top is
  port(
    clk_sys   : in  std_logic;
    reset_sys : in  std_logic;
    SCLK_in, MOSI_in, SS_in : in  std_logic;
    R_PWM_M1, L_PWM_M1 : out std_logic;
    R_EN_M1 , L_EN_M1  : out std_logic;
    R_PWM_M2, L_PWM_M2 : out std_logic;
    R_EN_M2 , L_EN_M2  : out std_logic
  );
end entity;

architecture structural of motor_ctrl_top is
  signal spi_byte : std_logic_vector(7 downto 0);
  signal ss_rise  : std_logic;
  signal load_pwm : std_logic;
  signal control_r, duty_r : std_logic_vector(7 downto 0);
  signal sel_RPWM_M1, sel_LPWM_M1 : std_logic;
  signal sel_RPWM_M2, sel_LPWM_M2 : std_logic;
  signal pwm_raw_M1, pwm_raw_M2 : std_logic;
  signal duty_nib_M1, duty_nib_M2 : std_logic_vector(3 downto 0);
begin
  u_spi : entity work.spi_slave_sync
    port map (
      clk_sys   => clk_sys,
      reset_sys => reset_sys,
      SCLK_in   => SCLK_in,
      MOSI_in   => MOSI_in,
      SS_in     => SS_in,
      data_out  => spi_byte
    );

  process(clk_sys)
    variable ss_d : std_logic := '1';
  begin
    if rising_edge(clk_sys) then
      ss_rise <= '0';
      if ss_d='0' and SS_in='1' then
        ss_rise <= '1';
      end if;
      ss_d := SS_in;
    end if;
  end process;

  u_fsm : entity work.ctrl_fsm
    port map (
      clk      => clk_sys,
      rst      => reset_sys,
      ss_rise  => ss_rise,
      byte_in  => spi_byte,
      load_pwm => load_pwm,
      control  => control_r,
      duty     => duty_r
    );

  u_dec : entity work.decoder
    port map(
      control => control_r,
      duty    => duty_r,
      duty_M1 => duty_nib_M1,
      duty_M2 => duty_nib_M2,
      R_PWM_M1 => sel_RPWM_M1, L_PWM_M1 => sel_LPWM_M1,
      R_PWM_M2 => sel_RPWM_M2, L_PWM_M2 => sel_LPWM_M2,
      R_EN_M1  => R_EN_M1 ,   L_EN_M1  => L_EN_M1 ,
      R_EN_M2  => R_EN_M2 ,   L_EN_M2  => L_EN_M2
    );

  u_pwm1 : entity work.pwm_module
    generic map (CNT_WIDTH=>4, DUTY_WIDTH=>4, DIV_CONST=>2399)
    port map (
      clk   => clk_sys,
      rst   => reset_sys,
      load  => load_pwm,
      ancho => duty_nib_M1,
      pwm   => pwm_raw_M1
    );

  u_pwm2 : entity work.pwm_module
    generic map (CNT_WIDTH=>4, DUTY_WIDTH=>4, DIV_CONST=>2399)
    port map (
      clk   => clk_sys,
      rst   => reset_sys,
      load  => load_pwm,
      ancho => duty_nib_M2,
      pwm   => pwm_raw_M2
    );

  R_PWM_M1 <= pwm_raw_M1 when sel_RPWM_M1='1' else '0';
  L_PWM_M1 <= pwm_raw_M1 when sel_LPWM_M1='1' else '0';
  R_PWM_M2 <= pwm_raw_M2 when sel_RPWM_M2='1' else '0';
  L_PWM_M2 <= pwm_raw_M2 when sel_LPWM_M2='1' else '0';
=======
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use work.pwm_pkg.all;

entity motor_ctrl_top is
  port(
    clk_sys   : in  std_logic;
    reset_sys : in  std_logic;
    SCLK_in, MOSI_in, SS_in : in  std_logic;
    R_PWM_M1, L_PWM_M1 : out std_logic;
    R_EN_M1 , L_EN_M1  : out std_logic;
    R_PWM_M2, L_PWM_M2 : out std_logic;
    R_EN_M2 , L_EN_M2  : out std_logic
  );
end entity;

architecture structural of motor_ctrl_top is
  signal spi_byte : std_logic_vector(7 downto 0);
  signal ss_rise  : std_logic;
  signal load_pwm : std_logic;
  signal control_r, duty_r : std_logic_vector(7 downto 0);
  signal sel_RPWM_M1, sel_LPWM_M1 : std_logic;
  signal sel_RPWM_M2, sel_LPWM_M2 : std_logic;
  signal pwm_raw_M1, pwm_raw_M2 : std_logic;
  signal duty_nib_M1, duty_nib_M2 : std_logic_vector(3 downto 0);
begin
  u_spi : entity work.spi_slave_sync
    port map (
      clk_sys   => clk_sys,
      reset_sys => reset_sys,
      SCLK_in   => SCLK_in,
      MOSI_in   => MOSI_in,
      SS_in     => SS_in,
      data_out  => spi_byte
    );

  process(clk_sys)
    variable ss_d : std_logic := '1';
  begin
    if rising_edge(clk_sys) then
      ss_rise <= '0';
      if ss_d='0' and SS_in='1' then
        ss_rise <= '1';
      end if;
      ss_d := SS_in;
    end if;
  end process;

  u_fsm : entity work.ctrl_fsm
    port map (
      clk      => clk_sys,
      rst      => reset_sys,
      ss_rise  => ss_rise,
      byte_in  => spi_byte,
      load_pwm => load_pwm,
      control  => control_r,
      duty     => duty_r
    );

  u_dec : entity work.decoder
    port map(
      control => control_r,
      duty    => duty_r,
      duty_M1 => duty_nib_M1,
      duty_M2 => duty_nib_M2,
      R_PWM_M1 => sel_RPWM_M1, L_PWM_M1 => sel_LPWM_M1,
      R_PWM_M2 => sel_RPWM_M2, L_PWM_M2 => sel_LPWM_M2,
      R_EN_M1  => R_EN_M1 ,   L_EN_M1  => L_EN_M1 ,
      R_EN_M2  => R_EN_M2 ,   L_EN_M2  => L_EN_M2
    );

  u_pwm1 : entity work.pwm_module
    generic map (CNT_WIDTH=>4, DUTY_WIDTH=>4, DIV_CONST=>2399)
    port map (
      clk   => clk_sys,
      rst   => reset_sys,
      load  => load_pwm,
      ancho => duty_nib_M1,
      pwm   => pwm_raw_M1
    );

  u_pwm2 : entity work.pwm_module
    generic map (CNT_WIDTH=>4, DUTY_WIDTH=>4, DIV_CONST=>2399)
    port map (
      clk   => clk_sys,
      rst   => reset_sys,
      load  => load_pwm,
      ancho => duty_nib_M2,
      pwm   => pwm_raw_M2
    );

  R_PWM_M1 <= pwm_raw_M1 when sel_RPWM_M1='1' else '0';
  L_PWM_M1 <= pwm_raw_M1 when sel_LPWM_M1='1' else '0';
  R_PWM_M2 <= pwm_raw_M2 when sel_RPWM_M2='1' else '0';
  L_PWM_M2 <= pwm_raw_M2 when sel_LPWM_M2='1' else '0';
>>>>>>> c247ddddf8102dd7b5f2e1b32e1eb3e55a767da4
end structural;