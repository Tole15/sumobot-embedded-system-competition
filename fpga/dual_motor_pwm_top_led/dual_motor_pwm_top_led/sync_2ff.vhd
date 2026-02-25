--  sync_2ff.vhd  ----------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity sync_2ff is
  port (clk,rst,d_async:in std_logic; q_sync:out std_logic);
end;

architecture rtl of sync_2ff is
  signal ff1,ff2:std_logic:='0';
begin
  process(clk)
  begin
    if rising_edge(clk) then
      if rst='1' then ff1<='0'; ff2<='0';
      else ff1<=d_async; ff2<=ff1; end if;
    end if;
  end process;
  q_sync<=ff2;
end rtl;
