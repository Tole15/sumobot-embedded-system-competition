library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity decoder is
  port(
    control      : in  std_logic_vector(7 downto 0);
    duty         : in  std_logic_vector(7 downto 0);
    duty_M1      : out std_logic_vector(3 downto 0);
    duty_M2      : out std_logic_vector(3 downto 0);
    R_PWM_M1, L_PWM_M1 : out std_logic;
    R_PWM_M2, L_PWM_M2 : out std_logic;
    R_EN_M1 , L_EN_M1  : out std_logic;
    R_EN_M2 , L_EN_M2  : out std_logic
  );
end entity;

architecture rtl of decoder is
  -- Alias directos a los bits del byte CONTROL
  signal sel_pwm_M1  : std_logic;  
  signal dir_M1      : std_logic;  
  signal sel_pwm_M2  : std_logic; 
  signal dir_M2      : std_logic; 
  signal en_code     : std_logic_vector(1 downto 0);  

  
  signal r_en_m1_i, l_en_m1_i : std_logic;
  signal r_en_m2_i, l_en_m2_i : std_logic;
begin
  
  sel_pwm_M1 <= control(1);
  dir_M1     <= control(0);
  sel_pwm_M2 <= control(3);
  dir_M2     <= control(2);
  en_code    <= control(5 downto 4);

 
  duty_M1 <= duty(7 downto 4);
  duty_M2 <= duty(3 downto 0);

  
  r_en_m1_i <= '1' when ((en_code="00" or en_code="10") and dir_M1='0') else '0';
  l_en_m1_i <= '1' when ((en_code="00" or en_code="10") and dir_M1='1') else '0';
  
  r_en_m2_i <= '1' when ((en_code="01" or en_code="10") and dir_M2='0') else '0';
  l_en_m2_i <= '1' when ((en_code="01" or en_code="10") and dir_M2='1') else '0';

  
  R_EN_M1 <= r_en_m1_i;
  L_EN_M1 <= l_en_m1_i;
  R_EN_M2 <= r_en_m2_i;
  L_EN_M2 <= l_en_m2_i;

  
  R_PWM_M1 <= '1' when sel_pwm_M1='0' else '0';
  L_PWM_M1 <= '1' when sel_pwm_M1='1' else '0';
  R_PWM_M2 <= '1' when sel_pwm_M2='0' else '0';
  L_PWM_M2 <= '1' when sel_pwm_M2='1' else '0';
end rtl;
