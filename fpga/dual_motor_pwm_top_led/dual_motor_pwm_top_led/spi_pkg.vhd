--  spi_pkg.vhd  (SIN duplicar sipo_reg ni regP)
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

package spi_pkg is
  ------------------------------------------------------------------
  --  Solo los bloques exclusivos del front-end SPI
  ------------------------------------------------------------------
  component sync_2ff
    port ( clk, rst, d_async : in  std_logic;
           q_sync            : out std_logic );
  end component;

  component edge_detect
    generic ( EDGE_TYPE : string := "RISE" );
    port ( clk, rst, din : in std_logic;
           pulse         : out std_logic );
  end component;

  ------------------------------------------------------------------
  --  FSM receptora de DOS bytes  (CONTROL y DUTY)
  ------------------------------------------------------------------
  component spi_fsm_rx
    port (
      clk        : in  std_logic;
      rst        : in  std_logic;
      ss_n       : in  std_logic;
      sclk_pulse : in  std_logic;
      shift_en   : out std_logic;
      load_ctrl  : out std_logic;
      load_duty  : out std_logic
    );
  end component;
end package;
