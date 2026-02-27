<<<<<<< HEAD
--  ContGen.vhd  -----------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity ContGen is
  generic (Nbits:integer:=4;Cuenta_Fin:integer:=15);
  port ( clk,CE,RST:in std_logic;
         conteo:out std_logic_vector(Nbits-1 downto 0);
         CEO   :out std_logic );
end;

architecture rtl of ContGen is
  signal c:unsigned(Nbits-1 downto 0):=(others=>'0');
begin
  conteo<=std_logic_vector(c);
  CEO   <='1' when (c=Cuenta_Fin) and CE='1' else '0';

  process(clk)
  begin
    if rising_edge(clk) then
      if RST='1' then c<=(others=>'0');
      elsif CE='1' then
        if c=Cuenta_Fin then c<=(others=>'0'); else c<=c+1; end if;
      end if;
    end if;
  end process;
end rtl;
=======
--  ContGen.vhd  -----------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity ContGen is
  generic (Nbits:integer:=4;Cuenta_Fin:integer:=15);
  port ( clk,CE,RST:in std_logic;
         conteo:out std_logic_vector(Nbits-1 downto 0);
         CEO   :out std_logic );
end;

architecture rtl of ContGen is
  signal c:unsigned(Nbits-1 downto 0):=(others=>'0');
begin
  conteo<=std_logic_vector(c);
  CEO   <='1' when (c=Cuenta_Fin) and CE='1' else '0';

  process(clk)
  begin
    if rising_edge(clk) then
      if RST='1' then c<=(others=>'0');
      elsif CE='1' then
        if c=Cuenta_Fin then c<=(others=>'0'); else c<=c+1; end if;
      end if;
    end if;
  end process;
end rtl;
>>>>>>> c247ddddf8102dd7b5f2e1b32e1eb3e55a767da4
