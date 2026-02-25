-- pwm_module.vhd
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use work.pwm_pkg.all;

entity pwm_module is
  generic (
    CNT_WIDTH  : natural := 4;
    DUTY_WIDTH : natural := 4;
    DIV_CONST  : natural := 2499  -- 50 MHz / (2499+1) = 20 kHz
  );
  port (
    clk   : in  std_logic;
    rst   : in  std_logic;
    load  : in  std_logic;
    ancho : in  std_logic_vector(DUTY_WIDTH-1 downto 0);
    pwm   : out std_logic
  );
end entity pwm_module;

architecture behavioral of pwm_module is
  constant DIV_WIDTH : natural := clog2(DIV_CONST + 1);

  signal DIV_CNT  : std_logic_vector(DIV_WIDTH-1 downto 0);
  signal FRECPWM  : std_logic;
  signal reload   : std_logic;
  signal CNT      : std_logic_vector(CNT_WIDTH-1 downto 0);
  signal shadow   : std_logic_vector(DUTY_WIDTH-1 downto 0);
  signal CMP      : std_logic_vector(DUTY_WIDTH-1 downto 0);
  signal load_reg : std_logic := '0';
begin

  -- Divisor de frecuencia para 20 kHz
  u_div : entity work.ContGen
    generic map (
      Nbits      => DIV_WIDTH,
      Cuenta_Fin => DIV_CONST
    )
    port map (
      clk    => clk,
      CE     => '1',
      RST    => rst,
      conteo => DIV_CNT,
      CEO    => FRECPWM
    );

  -- Contador PWM (4 bits)
  u_cnt : entity work.ContGen
    generic map (
      Nbits      => CNT_WIDTH,
      Cuenta_Fin => 2**CNT_WIDTH - 1
    )
    port map (
      clk    => clk,
      CE     => FRECPWM,
      RST    => rst,
      conteo => CNT,
      CEO    => reload
    );

  -- "Estira" la petición de load hasta que termine el periodo actual
  load_stretch: process(clk, rst)
  begin
    if rst = '1' then
      load_reg <= '0';
    elsif rising_edge(clk) then
      if load = '1' then
        load_reg <= '1';
      elsif reload = '1' then
        load_reg <= '0';
      end if;
    end if;
  end process;

  -- Registro sombra (captura ancho)
  u_reg_duty : entity work.regP
    generic map (WIDTH => DUTY_WIDTH)
    port map (
      clk  => clk,
      rst  => rst,
      load => load_reg,
      d    => ancho,
      q    => shadow
    );

  -- Registro CMP (sincronizado a reload)
  u_reg_shadow : entity work.regP
    generic map (WIDTH => DUTY_WIDTH)
    port map (
      clk  => clk,
      rst  => rst,
      load => reload,
      d    => shadow,
      q    => CMP
    );

  -- Generación de PWM
  pwm <= '1' when unsigned(CNT) < unsigned(CMP) else '0';

end architecture behavioral;
