--=======================================================================
--  tb_motor_ctrl_top.vhd   ·   Testbench para motor_ctrl_top
--=======================================================================
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity tb_motor_ctrl_top is
end entity;

architecture sim of tb_motor_ctrl_top is
  ------------------------------------------------------------------------
  --  Constantes temporales
  ----------------------------------------------------------------------
  constant CLK_SYS_PERIOD : time := 20 ns;          -- 50 MHz
  constant BIT_DELAY      : time := CLK_SYS_PERIOD * 4;

  ------------------------------------------------------------------------
  --  Señales del banco de prueba
  ----------------------------------------------------------------------
  signal clk_sys   : std_logic := '0';
  signal reset_sys : std_logic := '1';

  -- SPI maestro ? esclavo
  signal SCLK_in : std_logic := '0';
  signal MOSI_in : std_logic := '0';
  signal SS_in   : std_logic := '1';

  -- Salidas del DUT
  signal R_PWM_M1, L_PWM_M1 : std_logic;
  signal R_EN_M1 , L_EN_M1  : std_logic;
  signal R_PWM_M2, L_PWM_M2 : std_logic;
  signal R_EN_M2 , L_EN_M2  : std_logic;

  ----------------------------------------------------------------------
  --  PROCEDURE: envía un byte por SPI  (CKP=0, CKE=1, MSB-first)
  --             Nota: las señales se pasan como parámetros 'signal'
  ----------------------------------------------------------------------
  procedure spi_send_byte(
      signal SS   : out std_logic;
      signal SCLK : out std_logic;
      signal MOSI : out std_logic;
      constant byte_val : in std_logic_vector(7 downto 0))
  is
  begin
    SS <= '0';
    for i in 7 downto 0 loop
      MOSI <= byte_val(i);
      wait for BIT_DELAY;
      SCLK <= '1';
      wait for BIT_DELAY;
      SCLK <= '0';
    end loop;
    SS <= '1';                       -- latch del byte
    wait for BIT_DELAY * 2;          -- pausa entre tramas
  end procedure;

begin  --==========================  CUERPO  ==============================

  ----------------------------------------------------------------------
  -- Generador de reloj (50 MHz)
  clk_gen : process
  begin
    clk_sys <= '0';
    wait for CLK_SYS_PERIOD/2;
    clk_sys <= '1';
    wait for CLK_SYS_PERIOD/2;
  end process;

  ----------------------------------------------------------------------
  -- Reset de 200 ns
  reset_gen : process
  begin
    reset_sys <= '1';
    wait for 200 ns;
    reset_sys <= '0';
    wait;
  end process;

  ----------------------------------------------------------------------
  -- Instancia del diseño bajo prueba
  dut : entity work.motor_ctrl_top
    port map(
      clk_sys   => clk_sys,
      reset_sys => reset_sys,
      SCLK_in   => SCLK_in,
      MOSI_in   => MOSI_in,
      SS_in     => SS_in,
      R_PWM_M1  => R_PWM_M1, L_PWM_M1 => L_PWM_M1,
      R_EN_M1   => R_EN_M1 , L_EN_M1  => L_EN_M1,
      R_PWM_M2  => R_PWM_M2, L_PWM_M2 => L_PWM_M2,
      R_EN_M2   => R_EN_M2 , L_EN_M2  => L_EN_M2
    );

  ----------------------------------------------------------------------
  -- Estímulos
  ----------------------------------------------------------------------
  stim : process
  begin
    -- espera fin de reset
    wait until reset_sys = '0';
    wait for 1 us;

    -- Pareja 1 : CONTROL = 0x0A   DUTY = 0x51
    spi_send_byte(SS_in, SCLK_in, MOSI_in, "00001010");
    spi_send_byte(SS_in, SCLK_in, MOSI_in, "01010001");
    wait for 2 ms;                       -- observa salidas

    -- Pareja 2 : CONTROL = 0x2C   DUTY = 0xF3
    spi_send_byte(SS_in, SCLK_in, MOSI_in, "00101100");
    spi_send_byte(SS_in, SCLK_in, MOSI_in, "11110011");
    wait for 5 ms;                       -- silencio SPI

    -- Fin de simulación
    assert false report "FIN DE PRUEBA" severity failure;
    wait;                                -- evita warning 1369
  end process;

end architecture;
