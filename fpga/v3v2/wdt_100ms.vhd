library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

-- 48 MHz / 100 ms = 4 800 000 cuentas ? 23 bits bastan (2²³-1 = 8 388 607)
entity wdt_100ms is
  port(
    clk      : in  std_logic;
    rst      : in  std_logic;
    kick     : in  std_logic;              -- pulso: llegó DUTY (load_pwm)
    wdt_ok   : out std_logic               -- '1' = dentro de plazo
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
      elsif kick='1' then                 -- reinicio al llegar pareja nueva
        cnt <= (others=>'0');
      elsif cnt < TOP then
        cnt <= cnt + 1;
      end if;
    end if;
  end process;

  wdt_ok <= '1' when cnt < TOP else '0';
end rtl;
