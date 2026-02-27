library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity pwm_control is
    Port ( clk         : in  STD_LOGIC;
           reset       : in  STD_LOGIC;
           button      : in  STD_LOGIC;
           pwm_out     : out STD_LOGIC );
end pwm_control;

architecture Behavioral of pwm_control is

    signal counter    : integer range 0 to 9999 := 0;  -- Contador para el PWM
    signal pwm_cycle  : integer range 0 to 100 := 50;  -- Ciclo de trabajo del PWM (inicialmente al 50%)
    
    -- Variables para debounce
    signal button_reg : STD_LOGIC := '0';     -- Registro para el botón
    signal button_stable : STD_LOGIC := '0';  -- Estado estable del botón
    signal button_counter : integer range 0 to 1000000 := 0; -- Contador para debounce

begin

    -- Generador de PWM basado en un contador
    process(clk, reset)
    begin
        if reset = '1' then
            counter <= 0;
            pwm_out <= '0';
            pwm_cycle <= 50;  -- 50% de ciclo de trabajo inicial
            button_reg <= '0';
            button_stable <= '0';
            button_counter <= 0;
        elsif rising_edge(clk) then
            if counter < 9999 then
                counter <= counter + 1;
            else
                counter <= 0;
            end if;

            -- Ajusta la señal PWM dependiendo del contador y el ciclo de trabajo
            if counter < (pwm_cycle * 100) then
                pwm_out <= '1';
            else
                pwm_out <= '0';
            end if;

            -- Manejamos el botón con debounce
            if button = button_reg then
                if button_counter < 1000000 then
                    button_counter <= button_counter + 1;
                else
                    -- Solo se considera el cambio si el botón está estable por 1ms (aproximadamente)
                    if button = '1' and button_stable = '0' then
                        if pwm_cycle < 100 then
                            pwm_cycle <= pwm_cycle + 5;  -- Aumenta el ciclo de trabajo en un 5%
                        end if;
                        button_stable <= '1';  -- Marca el estado estable del botón
                    elsif button = '0' then
                        button_stable <= '0';  -- Reset cuando el botón se suelta
                    end if;
                end if;
            else
                button_counter <= 0;  -- Reinicia el contador si el botón cambia de estado
            end if;

            -- Actualizamos el registro del botón
            button_reg <= button;

        end if;
    end process;

end Behavioral;
