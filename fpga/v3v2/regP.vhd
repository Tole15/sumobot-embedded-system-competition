library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

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
  process(clk)
  begin
    if rising_edge(clk) then
      if rst='1' then
        reg_r <= (others=>'0');
      elsif load='1' then
        reg_r <= d;
      end if;
    end if;
  end process;
  q <= reg_r;
end behavioral;
