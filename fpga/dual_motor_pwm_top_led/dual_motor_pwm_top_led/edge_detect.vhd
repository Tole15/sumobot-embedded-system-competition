<<<<<<< HEAD
--  edge_detect.vhd  -------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity edge_detect is
  generic (EDGE_TYPE:string:="RISE");
  port (clk,rst,din:in std_logic; pulse:out std_logic);
end;

architecture rtl of edge_detect is
  signal prev,p:std_logic:='0';
begin
  process(clk)
  begin
    if rising_edge(clk) then
      if rst='1' then prev<='0'; p<='0';
      else
        p<='0';
        if (EDGE_TYPE="RISE" and din='1' and prev='0') or
           (EDGE_TYPE="FALL" and din='0' and prev='1') or
           (EDGE_TYPE="BOTH" and din/=prev) then p<='1'; end if;
        prev<=din;
      end if;
    end if;
  end process;
  pulse<=p;
=======
--  edge_detect.vhd  -------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity edge_detect is
  generic (EDGE_TYPE:string:="RISE");
  port (clk,rst,din:in std_logic; pulse:out std_logic);
end;

architecture rtl of edge_detect is
  signal prev,p:std_logic:='0';
begin
  process(clk)
  begin
    if rising_edge(clk) then
      if rst='1' then prev<='0'; p<='0';
      else
        p<='0';
        if (EDGE_TYPE="RISE" and din='1' and prev='0') or
           (EDGE_TYPE="FALL" and din='0' and prev='1') or
           (EDGE_TYPE="BOTH" and din/=prev) then p<='1'; end if;
        prev<=din;
      end if;
    end if;
  end process;
  pulse<=p;
>>>>>>> c247ddddf8102dd7b5f2e1b32e1eb3e55a767da4
end rtl;