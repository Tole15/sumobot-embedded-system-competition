library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

<<<<<<< HEAD
-- 48 MHz / 100 ms = 4 800 000 cuentas ? 23 bits bastan (2²³-1 = 8 388 607)
=======
>>>>>>> c247ddddf8102dd7b5f2e1b32e1eb3e55a767da4
entity wdt_100ms is
  port(
    clk      : in  std_logic;
    rst      : in  std_logic;
<<<<<<< HEAD
    kick     : in  std_logic;              -- pulso: llegó DUTY (load_pwm)
    wdt_ok   : out std_logic               -- '1' = dentro de plazo
=======
    kick     : in  std_logic;              
    wdt_ok   : out std_logic               
>>>>>>> c247ddddf8102dd7b5f2e1b32e1eb3e55a767da4
  );
end entity;

architecture rtl of wdt_100ms is
  constant TOP : unsigned(22 downto 0) := to_unsigned(4_799_999, 23);
  signal cnt   : unsigned(22 downto 0) := (others => '0');
begin
  process(clk)
  begin
    if rising_edge(clk) then
      if rst='1' then
        cnt <= (others=>'0');
<<<<<<< HEAD
      elsif kick='1' then                 -- reinicio al llegar pareja nueva
=======
      elsif kick='1' then                 
>>>>>>> c247ddddf8102dd7b5f2e1b32e1eb3e55a767da4
        cnt <= (others=>'0');
      elsif cnt < TOP then
        cnt <= cnt + 1;
      end if;
    end if;
  end process;

  wdt_ok <= '1' when cnt < TOP else '0';
end rtl;
