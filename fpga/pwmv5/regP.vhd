-- regP.vhd
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity regP is
  generic (
    WIDTH : natural := 8
  );
  port (
    clk  : in  std_logic;
    rst  : in  std_logic;
    load : in  std_logic;
    d    : in  std_logic_vector(WIDTH-1 downto 0);
    q    : out std_logic_vector(WIDTH-1 downto 0)
  );
end entity;

architecture behavioral of regP is
  signal reg_r : std_logic_vector(WIDTH-1 downto 0) := (others=>'0');
begin
  process(clk, rst)
  begin
    if rst='1' then
      reg_r <= (others=>'0');
    elsif rising_edge(clk) then
      if load='1' then
        reg_r <= d;
      end if;
    end if;
  end process;

  q <= reg_r;
end architecture;
