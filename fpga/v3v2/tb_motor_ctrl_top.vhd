
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity tb_motor_ctrl_top is
end entity;

architecture sim of tb_motor_ctrl_top is
  
  constant CLK_SYS_PERIOD : time := 20 ns;          -- 50 MHz
  constant BIT_DELAY      : time := CLK_SYS_PERIOD * 4;

  
  signal clk_sys   : std_logic := '0';
  signal reset_sys : std_logic := '1';

  
  signal SCLK_in : std_logic := '0';
  signal MOSI_in : std_logic := '0';
  signal SS_in   : std_logic := '1';

  
  signal R_PWM_M1, L_PWM_M1 : std_logic;
  signal R_EN_M1 , L_EN_M1  : std_logic;
  signal R_PWM_M2, L_PWM_M2 : std_logic;
  signal R_EN_M2 , L_EN_M2  : std_logic;

  
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

begin  
  clk_gen : process
  begin
    clk_sys <= '0';
    wait for CLK_SYS_PERIOD/2;
    clk_sys <= '1';
    wait for CLK_SYS_PERIOD/2;
  end process;

  
  reset_gen : process
  begin
    reset_sys <= '1';
    wait for 200 ns;
    reset_sys <= '0';
    wait;
  end process;

   Instancia del diseño bajo prueba
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

  
  stim : process
  begin
   
    wait until reset_sys = '0';
    wait for 1 us;

    
    spi_send_byte(SS_in, SCLK_in, MOSI_in, "00001010");
    spi_send_byte(SS_in, SCLK_in, MOSI_in, "01010001");
    wait for 2 ms;                       

    spi_send_byte(SS_in, SCLK_in, MOSI_in, "00101100");
    spi_send_byte(SS_in, SCLK_in, MOSI_in, "11110011");
    wait for 5 ms;                       

    
    assert false report "FIN DE PRUEBA" severity failure;
    wait;                                
  end process;

end architecture;
