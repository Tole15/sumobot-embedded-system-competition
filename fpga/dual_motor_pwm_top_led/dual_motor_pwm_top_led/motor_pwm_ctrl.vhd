<<<<<<< HEAD
--  motor_pwm_ctrl.vhd  ----------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use work.pwm_pkg.all;

entity motor_pwm_ctrl is
  generic (
    CNT_WIDTH  : natural := 4;
    DUTY_WIDTH : natural := 4;
    DIV_CONST  : natural := 2499
  );
  port (
    clk     : in  std_logic;
    rst     : in  std_logic;
    dir     : in  std_logic_vector(1 downto 0);   -- b1=subPWM, b0=L/R
    act     : in  std_logic_vector(1 downto 0);   -- 00/01/10
    duty_in : in  std_logic_vector(DUTY_WIDTH-1 downto 0);
    R_PWM_o : out std_logic;
    L_PWM_o : out std_logic;
    R_EN_o  : out std_logic;
    L_EN_o  : out std_logic
  );
end entity;

architecture rtl of motor_pwm_ctrl is
  --------------------------------------------------------------------
  --  Dos generadores PWM simples
  --------------------------------------------------------------------
  component pwm_module
    generic ( CNT_WIDTH:natural; DUTY_WIDTH:natural; DIV_CONST:natural );
    port ( clk,rst,load : in  std_logic;
           ancho        : in  std_logic_vector(DUTY_WIDTH-1 downto 0);
           pwm          : out std_logic );
  end component;

  signal pwm_r, pwm_l : std_logic;
  signal duty_reg     : std_logic_vector(DUTY_WIDTH-1 downto 0) := (others=>'0');

  --------------------------------------------------------------------
  --  FSM de seguridad
  --------------------------------------------------------------------
  type tState is (IDLE, START_EN, RUN, STOP_PWM, STOP_EN);
  signal state                : tState := IDLE;
  signal side                 : std_logic := '0';   -- 0 = R, 1 = L
  signal en_r, en_l           : std_logic := '0';
  signal pwm_out              : std_logic := '0';
begin
  --------------------------------------------------------------------
  --  Instancias PWM  (etiquetas SIN chocar con señales)
  --------------------------------------------------------------------
  pwmR_inst : pwm_module
    generic map (CNT_WIDTH, DUTY_WIDTH, DIV_CONST)
    port map   ( clk, rst, '0', duty_reg, pwm_r );

  pwmL_inst : pwm_module
    generic map (CNT_WIDTH, DUTY_WIDTH, DIV_CONST)
    port map   ( clk, rst, '0', duty_reg, pwm_l );

  --------------------------------------------------------------------
  --  Registro DUTY
  --------------------------------------------------------------------
  process(clk)
  begin
    if rising_edge(clk) then
      if rst = '1' then
        duty_reg <= (others=>'0');
      else
        duty_reg <= duty_in;
      end if;
    end if;
  end process;

  --------------------------------------------------------------------
  --  FSM
  --------------------------------------------------------------------
  process(clk)
  begin
    if rising_edge(clk) then
      if rst = '1' then
        state   <= IDLE;
        en_r    <= '0';
        en_l    <= '0';
        pwm_out <= '0';
        side    <= '0';
      else
        case state is
          ----------------------------------------------------------------
          when IDLE =>
            if act = "00" or act = "01" or act = "10" then
              side  <= dir(0);                 -- L/R del byte
              state <= START_EN;
            end if;

          ----------------------------------------------------------------
          when START_EN =>
            if side = '0' then
              en_r <= '1';
            else
              en_l <= '1';
            end if;
            state <= RUN;

          ----------------------------------------------------------------
          when RUN =>
            -- Selección de PWM según el lado
            if side = '0' then
              pwm_out <= pwm_r;
            else
              pwm_out <= pwm_l;
            end if;

            -- Orden de parada: act = "00"
            if act = "00" then
              state <= STOP_PWM;
            end if;

          ----------------------------------------------------------------
          when STOP_PWM =>
            pwm_out <= '0';
            state   <= STOP_EN;

          when STOP_EN =>
            en_r <= '0';
            en_l <= '0';
            state <= IDLE;
        end case;
      end if;
    end if;
  end process;

  --------------------------------------------------------------------
  --  Salidas
  --------------------------------------------------------------------
  R_PWM_o <= pwm_out when (side = '0') else '0';
  L_PWM_o <= pwm_out when (side = '1') else '0';
  R_EN_o  <= en_r;
  L_EN_o  <= en_l;
end rtl;
=======
--  motor_pwm_ctrl.vhd  ----------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use work.pwm_pkg.all;

entity motor_pwm_ctrl is
  generic (
    CNT_WIDTH  : natural := 4;
    DUTY_WIDTH : natural := 4;
    DIV_CONST  : natural := 2499
  );
  port (
    clk     : in  std_logic;
    rst     : in  std_logic;
    dir     : in  std_logic_vector(1 downto 0);   -- b1=subPWM, b0=L/R
    act     : in  std_logic_vector(1 downto 0);   -- 00/01/10
    duty_in : in  std_logic_vector(DUTY_WIDTH-1 downto 0);
    R_PWM_o : out std_logic;
    L_PWM_o : out std_logic;
    R_EN_o  : out std_logic;
    L_EN_o  : out std_logic
  );
end entity;

architecture rtl of motor_pwm_ctrl is
  --------------------------------------------------------------------
  --  Dos generadores PWM simples
  --------------------------------------------------------------------
  component pwm_module
    generic ( CNT_WIDTH:natural; DUTY_WIDTH:natural; DIV_CONST:natural );
    port ( clk,rst,load : in  std_logic;
           ancho        : in  std_logic_vector(DUTY_WIDTH-1 downto 0);
           pwm          : out std_logic );
  end component;

  signal pwm_r, pwm_l : std_logic;
  signal duty_reg     : std_logic_vector(DUTY_WIDTH-1 downto 0) := (others=>'0');

  --------------------------------------------------------------------
  --  FSM de seguridad
  --------------------------------------------------------------------
  type tState is (IDLE, START_EN, RUN, STOP_PWM, STOP_EN);
  signal state                : tState := IDLE;
  signal side                 : std_logic := '0';   -- 0 = R, 1 = L
  signal en_r, en_l           : std_logic := '0';
  signal pwm_out              : std_logic := '0';
begin
  --------------------------------------------------------------------
  --  Instancias PWM  (etiquetas SIN chocar con señales)
  --------------------------------------------------------------------
  pwmR_inst : pwm_module
    generic map (CNT_WIDTH, DUTY_WIDTH, DIV_CONST)
    port map   ( clk, rst, '0', duty_reg, pwm_r );

  pwmL_inst : pwm_module
    generic map (CNT_WIDTH, DUTY_WIDTH, DIV_CONST)
    port map   ( clk, rst, '0', duty_reg, pwm_l );

  --------------------------------------------------------------------
  --  Registro DUTY
  --------------------------------------------------------------------
  process(clk)
  begin
    if rising_edge(clk) then
      if rst = '1' then
        duty_reg <= (others=>'0');
      else
        duty_reg <= duty_in;
      end if;
    end if;
  end process;

  --------------------------------------------------------------------
  --  FSM
  --------------------------------------------------------------------
  process(clk)
  begin
    if rising_edge(clk) then
      if rst = '1' then
        state   <= IDLE;
        en_r    <= '0';
        en_l    <= '0';
        pwm_out <= '0';
        side    <= '0';
      else
        case state is
          ----------------------------------------------------------------
          when IDLE =>
            if act = "00" or act = "01" or act = "10" then
              side  <= dir(0);                 -- L/R del byte
              state <= START_EN;
            end if;

          ----------------------------------------------------------------
          when START_EN =>
            if side = '0' then
              en_r <= '1';
            else
              en_l <= '1';
            end if;
            state <= RUN;

          ----------------------------------------------------------------
          when RUN =>
            -- Selección de PWM según el lado
            if side = '0' then
              pwm_out <= pwm_r;
            else
              pwm_out <= pwm_l;
            end if;

            -- Orden de parada: act = "00"
            if act = "00" then
              state <= STOP_PWM;
            end if;

          ----------------------------------------------------------------
          when STOP_PWM =>
            pwm_out <= '0';
            state   <= STOP_EN;

          when STOP_EN =>
            en_r <= '0';
            en_l <= '0';
            state <= IDLE;
        end case;
      end if;
    end if;
  end process;

  --------------------------------------------------------------------
  --  Salidas
  --------------------------------------------------------------------
  R_PWM_o <= pwm_out when (side = '0') else '0';
  L_PWM_o <= pwm_out when (side = '1') else '0';
  R_EN_o  <= en_r;
  L_EN_o  <= en_l;
end rtl;
>>>>>>> c247ddddf8102dd7b5f2e1b32e1eb3e55a767da4
