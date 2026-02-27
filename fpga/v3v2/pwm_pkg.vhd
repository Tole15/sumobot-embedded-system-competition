library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

package pwm_pkg is
  function to_slv (val  : natural; width : positive)
<<<<<<< HEAD
           return std_logic_vector;
			  
  function clog2 (val : natural) return natural;
=======
           return std_logic_vector;
			  
  function clog2 (val : natural) return natural;
>>>>>>> c247ddddf8102dd7b5f2e1b32e1eb3e55a767da4
  
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

<<<<<<< HEAD
package body pwm_pkg is
=======
package body pwm_pkg is
>>>>>>> c247ddddf8102dd7b5f2e1b32e1eb3e55a767da4

  function to_slv (val  : natural; width : positive)
           return std_logic_vector is
  begin
    return std_logic_vector(to_unsigned(val, width));
<<<<<<< HEAD
  end;
  
=======
  end;
  
>>>>>>> c247ddddf8102dd7b5f2e1b32e1eb3e55a767da4
  function clog2 (val : natural) return natural is
    variable tmp : natural := val - 1;  -- 0?0 bits; 1?0 bits
    variable n   : natural := 0;
  begin
    while tmp > 0 loop
      tmp := tmp / 2;
      n   := n + 1;
    end loop;
    return n;
<<<<<<< HEAD
  end;
=======
  end;
>>>>>>> c247ddddf8102dd7b5f2e1b32e1eb3e55a767da4
  
end package body;
