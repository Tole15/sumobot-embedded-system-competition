library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

package pwm_pkg is
  function to_slv (val  : natural; width : positive)
           return std_logic_vector;
			  
  function clog2 (val : natural) return natural;
  
  component ContGen
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
  end component;
  component regP
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
  end component;

  component sipo_reg
    generic (
      WIDTH : natural := 8
    );
    port (
      clk      : in  std_logic;
      rst      : in  std_logic;
      shift_en : in  std_logic;
      din      : in  std_logic;
      q        : out std_logic_vector(WIDTH-1 downto 0)
    );
  end component;
end package;

package body pwm_pkg is

  function to_slv (val  : natural; width : positive)
           return std_logic_vector is
  begin
    return std_logic_vector(to_unsigned(val, width));
  end;
  
  function clog2 (val : natural) return natural is
    variable tmp : natural := val - 1;  -- 0?0 bits; 1?0 bits
    variable n   : natural := 0;
  begin
    while tmp > 0 loop
      tmp := tmp / 2;
      n   := n + 1;
    end loop;
    return n;
  end;
  
end package body;
