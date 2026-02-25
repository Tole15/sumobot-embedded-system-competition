--  sipo_reg.vhd  ----------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity sipo_reg is
  generic (WIDTH:natural:=8);
  port ( clk,rst,shift_en:in std_logic;
         din              :in std_logic;
         q                :out std_logic_vector(WIDTH-1 downto 0) );
end;

architecture rtl of sipo_reg is
  signal sh:std_logic_vector(WIDTH-1 downto 0):=(others=>'0');
begin
  process(clk)
  begin
    if rising_edge(clk) then
      if rst='1' then sh<=(others=>'0');
      elsif shift_en='1' then sh<=din & sh(WIDTH-1 downto 1);
      end if;
    end if;
  end process;
  q<=sh;
end rtl;
