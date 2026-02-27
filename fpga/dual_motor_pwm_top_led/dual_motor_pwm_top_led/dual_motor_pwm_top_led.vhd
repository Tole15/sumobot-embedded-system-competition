<<<<<<< HEAD
--=============================================================
--  dual_motor_pwm_top_led.vhd  • 16-LED versión depurada
--     • LED_DATA(7:0)  = último octeto recibido (CONTROL o DUTY)
--     • LED_OUT(7:0)   = EN y PWM de ambos motores
--         [7] R_EN0  [6] L_EN0  [5] R_EN1  [4] L_EN1
--         [3] R_PWM0 [2] L_PWM0 [1] R_PWM1 [0] L_PWM1
--=============================================================
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use work.pwm_pkg.all;
use work.spi_pkg.all;

entity dual_motor_pwm_top_led is
  generic (
    CNT_WIDTH  : natural := 4;
    DUTY_WIDTH : natural := 4;
    DIV_CONST  : natural := 2499          -- 50 MHz÷(2499+1)≈20 kHz
  );
  port (
    clk_sys  : in  std_logic;
    reset    : in  std_logic;
    -- SPI del PIC18 (CKP=0, CKE=1)
    SCLK_in  : in  std_logic;
    MOSI_in  : in  std_logic;
    SS_in    : in  std_logic;
    -- Salidas a BTS7960
    R_PWM    : out std_logic_vector(1 downto 0);
    L_PWM    : out std_logic_vector(1 downto 0);
    R_EN     : out std_logic_vector(1 downto 0);
    L_EN     : out std_logic_vector(1 downto 0);
    -- LED de depuración
    LED_DATA : out std_logic_vector(7 downto 0);
    LED_OUT  : out std_logic_vector(7 downto 0)
  );
end entity;

architecture rtl of dual_motor_pwm_top_led is
  --------------------------------------------------------------------------
  --  Sincronización SPI
  --------------------------------------------------------------------------
  signal sclk_s, mosi_s, ss_s, sclk_p : std_logic;
  signal shift_w, load_ctrl, load_duty : std_logic;
  signal sipo_q : std_logic_vector(7 downto 0);

  --------------------------------------------------------------------------
  --  Configuración motores
  --------------------------------------------------------------------------
  signal dir_m1, dir_m2 : std_logic_vector(1 downto 0);
  signal act_ctrl       : std_logic_vector(1 downto 0);
  signal duty_m1, duty_m2 : std_logic_vector(DUTY_WIDTH-1 downto 0);

  --------------------------------------------------------------------------
  --  Señales internas de salida  (para evitar leer puertos OUT)
  --------------------------------------------------------------------------
  signal r_pwm_i, l_pwm_i : std_logic_vector(1 downto 0);
  signal r_en_i , l_en_i  : std_logic_vector(1 downto 0);
begin
  --------------------------------------------------------------------------
  --  Sincronizadores + detector de flanco
  --------------------------------------------------------------------------
  sync_sclk : sync_2ff port map (clk_sys, reset, SCLK_in, sclk_s);
  sync_mosi : sync_2ff port map (clk_sys, reset, MOSI_in, mosi_s);
  sync_ss   : sync_2ff port map (clk_sys, reset, SS_in,   ss_s);

  ed_sclk : edge_detect
    generic map (EDGE_TYPE => "RISE")
    port map   (clk_sys, reset, sclk_s, sclk_p);

  --------------------------------------------------------------------------
  --  Receptor SPI (2 bytes) + SIPO
  --------------------------------------------------------------------------
  fsm : spi_fsm_rx
    port map ( clk_sys, reset, ss_s, sclk_p,
               shift_w, load_ctrl, load_duty );

  sipo : sipo_reg
    generic map (WIDTH => 8)
    port map   ( clk_sys, reset, shift_w, mosi_s, sipo_q );

  --------------------------------------------------------------------------
  --  Latch de bytes y LED_DATA
  --------------------------------------------------------------------------
  process(clk_sys)
  begin
    if rising_edge(clk_sys) then
      if reset = '1' then
        dir_m1   <= "00"; dir_m2   <= "00"; act_ctrl <= "00";
        duty_m1  <= (others=>'0'); duty_m2 <= (others=>'0');
        LED_DATA <= (others=>'0');
      elsif load_ctrl = '1' then         -- primer byte (CONTROL)
        dir_m1   <= sipo_q(1 downto 0);
        dir_m2   <= sipo_q(3 downto 2);
        act_ctrl <= sipo_q(5 downto 4);
        LED_DATA <= sipo_q;
      elsif load_duty = '1' then         -- segundo byte (DUTY)
        duty_m1  <= sipo_q(7 downto 4);
        duty_m2  <= sipo_q(3 downto 0);
        LED_DATA <= sipo_q;
      end if;
    end if;
  end process;

  --------------------------------------------------------------------------
  --  Motor 1
  --------------------------------------------------------------------------
  M1 : entity work.motor_pwm_ctrl
    generic map (CNT_WIDTH, DUTY_WIDTH, DIV_CONST)
    port map ( clk_sys, reset,
               dir_m1, act_ctrl, duty_m1,
               r_pwm_i(0), l_pwm_i(0), r_en_i(0), l_en_i(0) );

  --------------------------------------------------------------------------
  --  Motor 2
  --------------------------------------------------------------------------
  M2 : entity work.motor_pwm_ctrl
    generic map (CNT_WIDTH, DUTY_WIDTH, DIV_CONST)
    port map ( clk_sys, reset,
               dir_m2, act_ctrl, duty_m2,
               r_pwm_i(1), l_pwm_i(1), r_en_i(1), l_en_i(1) );

  --------------------------------------------------------------------------
  --  LED_OUT:  EN-EN-EN-EN-PWM-PWM-PWM-PWM
  --------------------------------------------------------------------------
  LED_OUT <= r_en_i(0) & l_en_i(0) & r_en_i(1) & l_en_i(1) &
             r_pwm_i(0)& l_pwm_i(0)& r_pwm_i(1)& l_pwm_i(1);

  --------------------------------------------------------------------------
  --  Puertos de salida hacia el mundo exterior
  --------------------------------------------------------------------------
  R_PWM <= r_pwm_i;
  L_PWM <= l_pwm_i;
  R_EN  <= r_en_i;
  L_EN  <= l_en_i;
end rtl;
=======
--=============================================================
--  dual_motor_pwm_top_led.vhd  • 16-LED versión depurada
--     • LED_DATA(7:0)  = último octeto recibido (CONTROL o DUTY)
--     • LED_OUT(7:0)   = EN y PWM de ambos motores
--         [7] R_EN0  [6] L_EN0  [5] R_EN1  [4] L_EN1
--         [3] R_PWM0 [2] L_PWM0 [1] R_PWM1 [0] L_PWM1
--=============================================================
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use work.pwm_pkg.all;
use work.spi_pkg.all;

entity dual_motor_pwm_top_led is
  generic (
    CNT_WIDTH  : natural := 4;
    DUTY_WIDTH : natural := 4;
    DIV_CONST  : natural := 2499          -- 50 MHz÷(2499+1)≈20 kHz
  );
  port (
    clk_sys  : in  std_logic;
    reset    : in  std_logic;
    -- SPI del PIC18 (CKP=0, CKE=1)
    SCLK_in  : in  std_logic;
    MOSI_in  : in  std_logic;
    SS_in    : in  std_logic;
    -- Salidas a BTS7960
    R_PWM    : out std_logic_vector(1 downto 0);
    L_PWM    : out std_logic_vector(1 downto 0);
    R_EN     : out std_logic_vector(1 downto 0);
    L_EN     : out std_logic_vector(1 downto 0);
    -- LED de depuración
    LED_DATA : out std_logic_vector(7 downto 0);
    LED_OUT  : out std_logic_vector(7 downto 0)
  );
end entity;

architecture rtl of dual_motor_pwm_top_led is
  --------------------------------------------------------------------------
  --  Sincronización SPI
  --------------------------------------------------------------------------
  signal sclk_s, mosi_s, ss_s, sclk_p : std_logic;
  signal shift_w, load_ctrl, load_duty : std_logic;
  signal sipo_q : std_logic_vector(7 downto 0);

  --------------------------------------------------------------------------
  --  Configuración motores
  --------------------------------------------------------------------------
  signal dir_m1, dir_m2 : std_logic_vector(1 downto 0);
  signal act_ctrl       : std_logic_vector(1 downto 0);
  signal duty_m1, duty_m2 : std_logic_vector(DUTY_WIDTH-1 downto 0);

  --------------------------------------------------------------------------
  --  Señales internas de salida  (para evitar leer puertos OUT)
  --------------------------------------------------------------------------
  signal r_pwm_i, l_pwm_i : std_logic_vector(1 downto 0);
  signal r_en_i , l_en_i  : std_logic_vector(1 downto 0);
begin
  --------------------------------------------------------------------------
  --  Sincronizadores + detector de flanco
  --------------------------------------------------------------------------
  sync_sclk : sync_2ff port map (clk_sys, reset, SCLK_in, sclk_s);
  sync_mosi : sync_2ff port map (clk_sys, reset, MOSI_in, mosi_s);
  sync_ss   : sync_2ff port map (clk_sys, reset, SS_in,   ss_s);

  ed_sclk : edge_detect
    generic map (EDGE_TYPE => "RISE")
    port map   (clk_sys, reset, sclk_s, sclk_p);

  --------------------------------------------------------------------------
  --  Receptor SPI (2 bytes) + SIPO
  --------------------------------------------------------------------------
  fsm : spi_fsm_rx
    port map ( clk_sys, reset, ss_s, sclk_p,
               shift_w, load_ctrl, load_duty );

  sipo : sipo_reg
    generic map (WIDTH => 8)
    port map   ( clk_sys, reset, shift_w, mosi_s, sipo_q );

  --------------------------------------------------------------------------
  --  Latch de bytes y LED_DATA
  --------------------------------------------------------------------------
  process(clk_sys)
  begin
    if rising_edge(clk_sys) then
      if reset = '1' then
        dir_m1   <= "00"; dir_m2   <= "00"; act_ctrl <= "00";
        duty_m1  <= (others=>'0'); duty_m2 <= (others=>'0');
        LED_DATA <= (others=>'0');
      elsif load_ctrl = '1' then         -- primer byte (CONTROL)
        dir_m1   <= sipo_q(1 downto 0);
        dir_m2   <= sipo_q(3 downto 2);
        act_ctrl <= sipo_q(5 downto 4);
        LED_DATA <= sipo_q;
      elsif load_duty = '1' then         -- segundo byte (DUTY)
        duty_m1  <= sipo_q(7 downto 4);
        duty_m2  <= sipo_q(3 downto 0);
        LED_DATA <= sipo_q;
      end if;
    end if;
  end process;

  --------------------------------------------------------------------------
  --  Motor 1
  --------------------------------------------------------------------------
  M1 : entity work.motor_pwm_ctrl
    generic map (CNT_WIDTH, DUTY_WIDTH, DIV_CONST)
    port map ( clk_sys, reset,
               dir_m1, act_ctrl, duty_m1,
               r_pwm_i(0), l_pwm_i(0), r_en_i(0), l_en_i(0) );

  --------------------------------------------------------------------------
  --  Motor 2
  --------------------------------------------------------------------------
  M2 : entity work.motor_pwm_ctrl
    generic map (CNT_WIDTH, DUTY_WIDTH, DIV_CONST)
    port map ( clk_sys, reset,
               dir_m2, act_ctrl, duty_m2,
               r_pwm_i(1), l_pwm_i(1), r_en_i(1), l_en_i(1) );

  --------------------------------------------------------------------------
  --  LED_OUT:  EN-EN-EN-EN-PWM-PWM-PWM-PWM
  --------------------------------------------------------------------------
  LED_OUT <= r_en_i(0) & l_en_i(0) & r_en_i(1) & l_en_i(1) &
             r_pwm_i(0)& l_pwm_i(0)& r_pwm_i(1)& l_pwm_i(1);

  --------------------------------------------------------------------------
  --  Puertos de salida hacia el mundo exterior
  --------------------------------------------------------------------------
  R_PWM <= r_pwm_i;
  L_PWM <= l_pwm_i;
  R_EN  <= r_en_i;
  L_EN  <= l_en_i;
end rtl;
>>>>>>> c247ddddf8102dd7b5f2e1b32e1eb3e55a767da4
