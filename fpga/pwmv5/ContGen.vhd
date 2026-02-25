-- ContGen.vhd
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity ContGen is
  generic (
    Nbits      : integer := 4;
    Cuenta_Fin : integer := 15
  );
  port (
    clk    : in  std_logic;
    CE     : in  std_logic;
    RST    : in  std_logic;
    conteo : out std_logic_vector(Nbits-1 downto 0);
    CEO    : out std_logic
  );
end entity;

architecture behavioral of ContGen is
  signal count_r : unsigned(Nbits-1 downto 0) := (others=>'0');
begin
  conteo <= std_logic_vector(count_r);
  CEO    <= '1' when (count_r = Cuenta_Fin and CE='1') else '0';

  process(clk, RST)
  begin
    if RST='1' then
      count_r <= (others=>'0');
    elsif rising_edge(clk) then
      if CE='1' then
        if count_r = Cuenta_Fin then
          count_r <= (others=>'0');
        else
          count_r <= count_r + 1;
        end if;
      end if;
    end if;
  end process;
end architecture;
