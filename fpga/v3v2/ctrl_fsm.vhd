library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity ctrl_fsm is
  port(
    clk     : in  std_logic;
    rst     : in  std_logic;
    ss_rise : in  std_logic;           -- flanco ? de SS (viene del SPI)
    byte_in : in  std_logic_vector(7 downto 0);
    load_pwm: out std_logic;           -- pulso: datos listos
    control : out std_logic_vector(7 downto 0);
    duty    : out std_logic_vector(7 downto 0)
  );
end entity;

architecture rtl of ctrl_fsm is
  type tByteSel is (EXPECT_CTRL, EXPECT_DUTY);
  signal state : tByteSel := EXPECT_CTRL;
  signal reg_ctrl, reg_duty : std_logic_vector(7 downto 0);
begin
  process(clk)
  begin
    if rising_edge(clk) then
      if rst='1' then
        state     <= EXPECT_CTRL;
        reg_ctrl  <= (others=>'0');
        reg_duty  <= (others=>'0');
        load_pwm  <= '0';
      else
        load_pwm <= '0';
        if ss_rise='1' then             -- acaba de llegar un byte
          case state is
            when EXPECT_CTRL =>
              reg_ctrl <= byte_in;
              state    <= EXPECT_DUTY;
            when EXPECT_DUTY =>
              reg_duty <= byte_in;
              load_pwm <= '1';           -- pareja completa
              state    <= EXPECT_CTRL;
          end case;
        end if;
      end if;
    end if;
  end process;

  control <= reg_ctrl;
  duty    <= reg_duty;
end rtl;
