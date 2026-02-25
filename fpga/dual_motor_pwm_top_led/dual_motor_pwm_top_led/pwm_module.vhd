--  pwm_module.vhd  --------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use work.pwm_pkg.all;

entity pwm_module is
  generic ( CNT_WIDTH:natural:=4; DUTY_WIDTH:natural:=4; DIV_CONST:natural:=2499 );
  port ( clk,rst,load:in std_logic;
         ancho        :in std_logic_vector(DUTY_WIDTH-1 downto 0);
         pwm          :out std_logic );
end;

architecture beh of pwm_module is
  constant DIV_WIDTH:natural:=clog2(DIV_CONST+1);
  signal div_cnt:std_logic_vector(DIV_WIDTH-1 downto 0);
  signal tick    :std_logic;
  signal cnt     :std_logic_vector(CNT_WIDTH-1 downto 0);
  signal shadow,CMP:std_logic_vector(DUTY_WIDTH-1 downto 0);
begin
  u_div:ContGen generic map(DIV_WIDTH,DIV_CONST)
        port map(clk,'1',rst,div_cnt,tick);

  u_cnt:ContGen generic map(CNT_WIDTH,2**CNT_WIDTH-1)
        port map(clk,'1',tick,cnt,open);

  u_reg1:regP generic map(DUTY_WIDTH)
        port map(clk,rst,load,ancho,shadow);
  u_reg2:regP generic map(DUTY_WIDTH)
        port map(clk,rst,tick,shadow,CMP);

  pwm <= '1' when unsigned(cnt)<=unsigned(CMP) else '0';
end beh;
