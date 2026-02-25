-- ctrl_fsm.vhd
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity ctrl_fsm is
  port(
    clk       : in  std_logic;
    rst       : in  std_logic;
    ss_rise   : in  std_logic;            -- flanco de SS
    byte_in   : in  std_logic_vector(7 downto 0);
    load_pwm  : out std_logic;            -- pulso de datos completos
    control   : out std_logic_vector(7 downto 0);
    duty      : out std_logic_vector(7 downto 0);
    error     : out std_logic             -- nueva señal de error
  );
end entity;

architecture rtl of ctrl_fsm is
  type tByteSel is (EXPECT_CTRL, EXPECT_DUTY);
  signal state      : tByteSel := EXPECT_CTRL;
  signal reg_ctrl   : std_logic_vector(7 downto 0) := (others=>'0');
  signal reg_duty   : std_logic_vector(7 downto 0) := (others=>'0');
  signal timeout_cnt: integer range 0 to 100000 := 0;
begin

  process(clk, rst)
  begin
    if rst='1' then
      state       <= EXPECT_CTRL;
      reg_ctrl    <= (others=>'0');
      reg_duty    <= (others=>'0');
      load_pwm    <= '0';
      error       <= '0';
      timeout_cnt <= 0;
    elsif rising_edge(clk) then
      -- clear pulso por defecto
      load_pwm <= '0';
      error    <= '0';

      -- timeout de segundo byte
      if state = EXPECT_DUTY then
        if timeout_cnt < 50000 then
          timeout_cnt <= timeout_cnt + 1;
        else
          state <= EXPECT_CTRL;
          timeout_cnt <= 0;
          error <= '1';  -- timeout
        end if;
      end if;

      if ss_rise='1' then
        timeout_cnt <= 0;
        case state is
          when EXPECT_CTRL =>
            reg_ctrl <= byte_in;
            state    <= EXPECT_DUTY;

          when EXPECT_DUTY =>
            reg_duty <= byte_in;
            load_pwm <= '1';
            state    <= EXPECT_CTRL;
        end case;
      end if;
    end if;
  end process;

  control <= reg_ctrl;
  duty    <= reg_duty;

end architecture rtl;
