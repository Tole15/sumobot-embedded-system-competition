library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity tb_pwm_control is
    -- No tiene puertos, es un testbench
end tb_pwm_control;

architecture behavior of tb_pwm_control is

    -- Component declaration para el módulo PWM
    component pwm_control
        Port ( clk         : in  STD_LOGIC;
               reset       : in  STD_LOGIC;
               button      : in  STD_LOGIC;
               pwm_out     : out STD_LOGIC );
    end component;

    -- Señales para conectar con el módulo PWM
    signal clk         : STD_LOGIC := '0';
    signal reset       : STD_LOGIC := '0';
    signal button      : STD_LOGIC := '0';
    signal pwm_out     : STD_LOGIC;

    -- Generar un reloj de 10ns (frecuencia de 100 MHz)
    constant clk_period : time := 10 ns;

begin
    -- Instancia del módulo PWM
    uut: pwm_control port map (
        clk => clk,
        reset => reset,
        button => button,
        pwm_out => pwm_out
    );

    -- Generación del reloj (10 ns de periodo)
    clk_process : process
    begin
        clk <= '0';
        wait for clk_period / 2;
        clk <= '1';
        wait for clk_period / 2;
    end process;

    -- Proceso de estímulos (simula la presión del botón)
    stimulus_process : process
    begin
        -- Reseteamos al inicio
        reset <= '1';
        wait for 20 ns;
        reset <= '0';
        
        -- Sin presionar el botón, el PWM tiene un ciclo de trabajo inicial
        wait for 100 ns;
        
        -- Simulamos la presión del botón (ciclo de trabajo aumenta)
        button <= '1';  -- Simula la presión del botón
        wait for 100 ns;
        
        button <= '0';  -- Simula la liberación del botón
        wait for 100 ns;
        
        -- Simulamos varias presiones para aumentar el ciclo de trabajo
        button <= '1';
        wait for 100 ns;
        
        button <= '0';
        wait for 100 ns;
        
        -- Continuamos con el ciclo de prueba
        button <= '1';
        wait for 100 ns;
        
        -- Finalizamos la simulación
        wait for 100 ns;
        assert false report "Fin de la simulación" severity failure;
    end process;

end behavior;
