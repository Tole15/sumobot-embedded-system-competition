-- tb_motor_ctrl_top.vhd
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity tb_motor_ctrl_top is
end entity tb_motor_ctrl_top;

architecture sim of tb_motor_ctrl_top is
  -- Señales de prueba
  signal clk_sys    : std_logic := '0';
  signal reset_sys  : std_logic := '1';
  signal SCLK_in    : std_logic := '0';
  signal MOSI_in    : std_logic := '0';
  signal SS_in      : std_logic := '1';

  signal R_PWM_M1   : std_logic;
  signal L_PWM_M1   : std_logic;
  signal R_EN_M1    : std_logic;
  signal L_EN_M1    : std_logic;
  signal R_PWM_M2   : std_logic;
  signal L_PWM_M2   : std_logic;
  signal R_EN_M2    : std_logic;
  signal L_EN_M2    : std_logic;

  -- Periodos de reloj
  constant SYS_PERIOD    : time := 20 ns;   -- 50 MHz
  constant SPI_QUARTER   : time := 333 ns;  -- 1.333 µs / 4
  constant SPI_HALF      : time := 667 ns;  -- 1.333 µs / 2

  -- Bytes a enviar
  constant CTRL : std_logic_vector(7 downto 0) := x"14";
  constant DUTY : std_logic_vector(7 downto 0) := x"A3";
begin

  ------------------------------------------------------------------------
  -- Generador de clk_sys (50 MHz)
  clk_proc: process
  begin
    while true loop
      clk_sys <= '0'; wait for SYS_PERIOD/2;
      clk_sys <= '1'; wait for SYS_PERIOD/2;
    end loop;
  end process;

  ------------------------------------------------------------------------
  -- Estímulos SPI + reset
  stim_proc: process
    variable i : integer;
  begin
    -- Inicialización
    SS_in     <= '1';
    MOSI_in   <= '0';
    SCLK_in   <= '0';
    reset_sys <= '1';
    wait for 200 ns;

    -- Desactiva reset
    reset_sys <= '0';
    wait for 200 ns;

    -- ===== Envío de CONTROL =====
    SS_in <= '0';
    wait for 2*SYS_PERIOD;  -- margen para filtro SS
    for i in 7 downto 0 loop
      MOSI_in <= CTRL(i);
      wait for SPI_QUARTER;
      SCLK_in <= '1';
      wait for SPI_HALF;
      SCLK_in <= '0';
    end loop;
    wait for SPI_QUARTER;
    SS_in <= '1';
    wait for 2*SYS_PERIOD;

    -- ===== Envío de DUTY =====
    SS_in <= '0';
    wait for 2*SYS_PERIOD;
    for i in 7 downto 0 loop
      MOSI_in <= DUTY(i);
      wait for SPI_QUARTER;
      SCLK_in <= '1';
      wait for SPI_HALF;
      SCLK_in <= '0';
    end loop;
    wait for SPI_QUARTER;
    SS_in <= '1';
    wait for 2*SYS_PERIOD;

    -- Dejar correr PWM unos ciclos (~300 µs)
    wait for 300 us;

    -- Fin de simulación
    assert false report "End of simulation" severity failure;
  end process;

  ------------------------------------------------------------------------
  -- Instancia del DUT
  u_dut: entity work.motor_ctrl_top
    port map (
      clk_sys   => clk_sys,
      reset_sys => reset_sys,
      SCLK_in   => SCLK_in,
      MOSI_in   => MOSI_in,
      SS_in     => SS_in,
      R_PWM_M1  => R_PWM_M1,
      L_PWM_M1  => L_PWM_M1,
      R_EN_M1   => R_EN_M1,
      L_EN_M1   => L_EN_M1,
      R_PWM_M2  => R_PWM_M2,
      L_PWM_M2  => L_PWM_M2,
      R_EN_M2   => R_EN_M2,
      L_EN_M2   => L_EN_M2
    );

end architecture sim;
