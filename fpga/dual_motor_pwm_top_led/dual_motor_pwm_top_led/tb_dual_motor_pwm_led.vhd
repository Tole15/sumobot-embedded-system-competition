---------------------------------------------------------------------------
--  tb_dual_motor_pwm_led.vhd   (ISE / ModelSim compatible)
---------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity tb_dual_motor_pwm_led is end;
architecture tb of tb_dual_motor_pwm_led is
  -------------------------------------------------------------------------
  --  Constantes temporales
  -------------------------------------------------------------------------
  constant CLK_SYS_PER : time := 20 ns;            -- 50 MHz
  constant SCLK_PER    : time := 333.333 ns;       -- 3 MHz  (48/16)
  constant T_BYTE_GAP  : time := 500 ms;           -- pausa entre bytes
  constant T_PAIR_GAP  : time := 1 sec;            -- pausa tras cada pareja

  -------------------------------------------------------------------------
  --  Señales DUT
  -------------------------------------------------------------------------
  signal clk_sys               : std_logic := '0';
  signal rst                   : std_logic := '0';
  signal SCLK, MOSI, SS        : std_logic := '1';
  signal R_PWM , L_PWM ,
         R_EN  , L_EN          : std_logic_vector(1 downto 0);
  signal LED_DATA, LED_OUT     : std_logic_vector(7 downto 0);

  -------------------------------------------------------------------------
  --  ***** Procedimiento de transmisión SPI (fuera de los procesos) *****
  -------------------------------------------------------------------------
  procedure spi_tx_byte(
      signal SCLK : out std_logic;
      signal MOSI : out std_logic;
      signal SS   : out std_logic;
      constant B  : in  std_logic_vector(7 downto 0)) is
  begin
      SS <= '0';
      for i in 7 downto 0 loop           -- MSB first
          MOSI <= B(i);
          SCLK <= '0';
          wait for SCLK_PER/2;
          SCLK <= '1';                   -- CKP=0 CKE=1 -> flanco de subida
          wait for SCLK_PER/2;
      end loop;
      SCLK <= '0';
      SS   <= '1';
      wait for T_BYTE_GAP;               -- 500 ms entre bytes
  end procedure;

begin
  -------------------------------------------------------------------------
  --  Reloj 50 MHz
  -------------------------------------------------------------------------
  clk_sys <= not clk_sys after CLK_SYS_PER/2;

  -------------------------------------------------------------------------
  --  Instancia del diseño bajo prueba
  -------------------------------------------------------------------------
  DUT : entity work.dual_motor_pwm_top_led
    port map (
      clk_sys  => clk_sys,
      reset    => rst,
      SCLK_in  => SCLK,
      MOSI_in  => MOSI,
      SS_in    => SS,
      R_PWM    => R_PWM,
      L_PWM    => L_PWM,
      R_EN     => R_EN,
      L_EN     => L_EN,
      LED_DATA => LED_DATA,
      LED_OUT  => LED_OUT
    );

  -------------------------------------------------------------------------
  --  Estímulo principal
  -------------------------------------------------------------------------
  stim : process
  begin
      -----------------------------------------------------------
      -- RESET
      -----------------------------------------------------------
      rst <= '1';
      wait for 1 us;
      rst <= '0';
      wait for 5 ms;

      -----------------------------------------------------------
      -- Pareja 1  (Motor-1 horario, duty 50 %)
      -----------------------------------------------------------
      spi_tx_byte(SCLK, MOSI, SS, "00000000");   -- CONTROL
      spi_tx_byte(SCLK, MOSI, SS, "10000000");   -- DUTY
      report "Pareja 1 completada" severity note;
      wait for T_PAIR_GAP;

      -----------------------------------------------------------
      -- Pareja 2  (Motor-2 antihorario, duty 100 %)
      -----------------------------------------------------------
      spi_tx_byte(SCLK, MOSI, SS, "00101100");   -- CONTROL
      spi_tx_byte(SCLK, MOSI, SS, "00001111");   -- DUTY
      report "Pareja 2 completada" severity note;
      wait for T_PAIR_GAP;

      -----------------------------------------------------------
      -- Pareja 3  (Parar ambos motores)
      -----------------------------------------------------------
      spi_tx_byte(SCLK, MOSI, SS, "00110000");   -- CONTROL
      spi_tx_byte(SCLK, MOSI, SS, "00000000");   -- DUTY
      report "Pareja 3 completada - STOP" severity note;
      wait for T_PAIR_GAP;

      -- Fin de simulación
      assert false report "FIN de simulación" severity failure;
  end process;
end tb;
