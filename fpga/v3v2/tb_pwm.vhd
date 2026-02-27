library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity tb_pwm is end;
architecture sim of tb_pwm is
  constant CLK_PER : time := 20 ns;  -- 50 MHz
  signal clk   : std_logic := '0';
  signal rst   : std_logic := '1';
  signal load  : std_logic := '0';
  signal ancho : std_logic_vector(3 downto 0) := (others=>'0');
  signal pwm   : std_logic;
begin
  -- Clock
  clk <= not clk after CLK_PER/2;

  -- UUT
  uut : entity work.pwm_module
    generic map (
      CNT_WIDTH  => 4,
      DUTY_WIDTH => 4,
      DIV_CONST  => 2499          -- 20 kHz
    )
    port map (
      clk   => clk,
      rst   => rst,
      load  => load,
      ancho => ancho,
      pwm   => pwm
    );

  -- Stimulus
  process
  begin
    wait for 200 ns;      -- Reset pulse
    rst <= '0';

<<<<<<< HEAD
    ancho <= "0111";      -- 7/16 ˜ 43.75 %
=======
    ancho <= "0111";      -- 7/16 Ëœ 43.75 %
>>>>>>> c247ddddf8102dd7b5f2e1b32e1eb3e55a767da4
    load  <= '1';
    wait for CLK_PER;
    load  <= '0';

<<<<<<< HEAD
    wait for 2 ms;        -- Observe varios ciclos (40 periodos)
    assert false report "FIN de simulación" severity failure;
=======
    wait for 2 ms;        
    assert false report "FIN de simulaciÃ³n" severity failure;
>>>>>>> c247ddddf8102dd7b5f2e1b32e1eb3e55a767da4
  end process;
end sim;
