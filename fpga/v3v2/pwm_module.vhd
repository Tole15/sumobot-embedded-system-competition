	library IEEE;
	use IEEE.STD_LOGIC_1164.ALL;
	use IEEE.NUMERIC_STD.ALL;
	use work.pwm_pkg.all;

	entity pwm_module is
	  generic (
		 CNT_WIDTH  : natural := 4;
		 DUTY_WIDTH : natural := 4;
		 DIV_CONST  : natural := 2499         -- 50 MHz / (2499+1) = 20 kHz
	  );
	  port (
		 clk   : in  std_logic;
		 rst   : in  std_logic;
		 load  : in  std_logic;                             
		 ancho : in  std_logic_vector(DUTY_WIDTH-1 downto 0);
		 pwm   : out std_logic
	  );
	end entity;

	architecture behavioral of pwm_module is
<<<<<<< HEAD

=======

>>>>>>> c247ddddf8102dd7b5f2e1b32e1eb3e55a767da4
		constant DIV_WIDTH : natural := clog2(DIV_CONST + 1);

	  signal DIV_CNT : std_logic_vector(DIV_WIDTH-1 downto 0);
	  signal FRECPWM : std_logic;
	  signal CNT : std_logic_vector(CNT_WIDTH-1 downto 0);
	  signal shadow : std_logic_vector(DUTY_WIDTH-1 downto 0);
	  signal CMP    : std_logic_vector(DUTY_WIDTH-1 downto 0);
	  signal reload : std_logic;

<<<<<<< HEAD
	begin
=======
	begin
>>>>>>> c247ddddf8102dd7b5f2e1b32e1eb3e55a767da4

	  u_div : ContGen
		 generic map (Nbits => DIV_WIDTH, Cuenta_Fin => DIV_CONST)
		 port map (
			clk    => clk,
			CE     => '1',
			RST    => rst,
			conteo => DIV_CNT,
			CEO    => FRECPWM
<<<<<<< HEAD
		 );
=======
		 );
>>>>>>> c247ddddf8102dd7b5f2e1b32e1eb3e55a767da4

	  u_cnt : ContGen
		 generic map (Nbits => CNT_WIDTH, Cuenta_Fin => 2**CNT_WIDTH - 1)
		 port map (
			clk    => clk,
			CE     => FRECPWM,
			RST    => rst,           
			conteo => CNT,
			CEO    => reload
		 );


	  u_reg_duty : regP
		 generic map (WIDTH => DUTY_WIDTH)
		 port map (
			clk  => clk,
			rst  => rst,
			load => load,
			d    => ancho,
			q    => shadow
		 );


	  u_reg_shadow : regP
		 generic map (WIDTH => DUTY_WIDTH)
		 port map (
			clk  => clk,
			rst  => rst,
			load => reload,
			d    => shadow,
			q    => CMP
		 );

	  pwm <= '1' when unsigned(CNT) < unsigned(CMP) else '0';

	end behavioral;
<<<<<<< HEAD


=======


>>>>>>> c247ddddf8102dd7b5f2e1b32e1eb3e55a767da4
