<<<<<<< HEAD
--  spi_fsm_rx.vhd  --------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity spi_fsm_rx is
  port ( clk,rst       :in  std_logic;
         ss_n          :in  std_logic;
         sclk_pulse    :in  std_logic;
         shift_en      :out std_logic;
         load_ctrl     :out std_logic;
         load_duty     :out std_logic );
end;

architecture rtl of spi_fsm_rx is
  type tState is (IDLE1,SHIFT1,IDLE2,SHIFT2);
  signal st:tState:=IDLE1;
  signal sh,lctrl,lduty:std_logic:='0';
begin
  shift_en  <= sh;
  load_ctrl <= lctrl;
  load_duty <= lduty;

  process(clk)
  begin
    if rising_edge(clk) then
      if rst='1' then st<=IDLE1; sh<='0'; lctrl<='0'; lduty<='0';
      else
        sh<='0'; lctrl<='0'; lduty<='0';
        case st is
          when IDLE1  => if ss_n='0' then st<=SHIFT1; end if;
          when SHIFT1 =>
            if ss_n='0' then if sclk_pulse='1' then sh<='1'; end if;
            else lctrl<='1'; st<=IDLE2; end if;
          when IDLE2  => if ss_n='0' then st<=SHIFT2; end if;
          when SHIFT2 =>
            if ss_n='0' then if sclk_pulse='1' then sh<='1'; end if;
            else lduty<='1'; st<=IDLE1; end if;
        end case;
      end if;
    end if;
  end process;
end rtl;
=======
--  spi_fsm_rx.vhd  --------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity spi_fsm_rx is
  port ( clk,rst       :in  std_logic;
         ss_n          :in  std_logic;
         sclk_pulse    :in  std_logic;
         shift_en      :out std_logic;
         load_ctrl     :out std_logic;
         load_duty     :out std_logic );
end;

architecture rtl of spi_fsm_rx is
  type tState is (IDLE1,SHIFT1,IDLE2,SHIFT2);
  signal st:tState:=IDLE1;
  signal sh,lctrl,lduty:std_logic:='0';
begin
  shift_en  <= sh;
  load_ctrl <= lctrl;
  load_duty <= lduty;

  process(clk)
  begin
    if rising_edge(clk) then
      if rst='1' then st<=IDLE1; sh<='0'; lctrl<='0'; lduty<='0';
      else
        sh<='0'; lctrl<='0'; lduty<='0';
        case st is
          when IDLE1  => if ss_n='0' then st<=SHIFT1; end if;
          when SHIFT1 =>
            if ss_n='0' then if sclk_pulse='1' then sh<='1'; end if;
            else lctrl<='1'; st<=IDLE2; end if;
          when IDLE2  => if ss_n='0' then st<=SHIFT2; end if;
          when SHIFT2 =>
            if ss_n='0' then if sclk_pulse='1' then sh<='1'; end if;
            else lduty<='1'; st<=IDLE1; end if;
        end case;
      end if;
    end if;
  end process;
end rtl;
>>>>>>> c247ddddf8102dd7b5f2e1b32e1eb3e55a767da4
