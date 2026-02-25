-- spi_slave_sync.vhd
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity spi_slave_sync is
  generic(
    DATA_WIDTH : integer := 8
  );
  port(
    clk_sys    : in  std_logic;
    reset_sys  : in  std_logic;  -- ya es rst_sync del top
    SCLK_in    : in  std_logic;
    MOSI_in    : in  std_logic;
    SS_in      : in  std_logic;  -- ya filtrado en el top
    data_out   : out std_logic_vector(DATA_WIDTH-1 downto 0)
  );
end entity;

architecture Behavioral of spi_slave_sync is
  signal SCLK_sync, SCLK_sync2 : std_logic := '0';
  signal MOSI_sync, MOSI_sync2 : std_logic := '0';
  signal SS_sync,   SS_sync2   : std_logic := '1';
  signal sclk_prev             : std_logic := '0';
  signal sclk_rise             : std_logic := '0';

  -- Estados one-hot con espera de SS alta
  type tState is (ST_IDLE, ST_SHIFT, ST_WAIT_SS_HIGH);
  signal rState : tState := ST_IDLE;

  signal shift_reg : std_logic_vector(DATA_WIDTH-1 downto 0) := (others=>'0');
  signal final_reg : std_logic_vector(DATA_WIDTH-1 downto 0) := (others=>'0');

  -- Contador de timeout de SCLK (opcional, aquí simple)
  constant TIMEOUT_MAX : integer := 1000;
  signal timeout_cnt   : integer range 0 to TIMEOUT_MAX := 0;
begin
  data_out <= final_reg;

  -- Doble sincronización entradas
  sync_inputs: process(clk_sys, reset_sys)
  begin
    if reset_sys='1' then
      SCLK_sync  <= '0'; SCLK_sync2  <= '0';
      MOSI_sync  <= '0'; MOSI_sync2  <= '0';
      SS_sync    <= '1'; SS_sync2    <= '1';
    elsif rising_edge(clk_sys) then
      SCLK_sync  <= SCLK_in;
      MOSI_sync  <= MOSI_in;
      SS_sync    <= SS_in;
      SCLK_sync2 <= SCLK_sync;
      MOSI_sync2 <= MOSI_sync;
      SS_sync2   <= SS_sync;
    end if;
  end process;

  -- Detecta flanco de subida de SCLK
  detect_sclk: process(clk_sys, reset_sys)
  begin
    if reset_sys='1' then
      sclk_prev <= '0';
      sclk_rise <= '0';
    elsif rising_edge(clk_sys) then
      sclk_rise <= '0';
      if (SCLK_sync2='1' and sclk_prev='0') then
        sclk_rise <= '1';
      end if;
      sclk_prev <= SCLK_sync2;
    end if;
  end process;

  -- FSM con timeout y espera de SS alta
  spi_fsm: process(clk_sys, reset_sys)
  begin
    if reset_sys='1' then
      rState      <= ST_IDLE;
      shift_reg   <= (others=>'0');
      final_reg   <= (others=>'0');
      timeout_cnt <= 0;
    elsif rising_edge(clk_sys) then
      case rState is
        when ST_IDLE =>
          if SS_sync2='0' then
            rState      <= ST_SHIFT;
            timeout_cnt <= 0;
          end if;

        when ST_SHIFT =>
          if SS_sync2='0' then
            if sclk_rise='1' then
              shift_reg <= MOSI_sync2 & shift_reg(DATA_WIDTH-1 downto 1);
            end if;
            -- Timeout si no llega SCLK
            if timeout_cnt < TIMEOUT_MAX then
              timeout_cnt <= timeout_cnt + 1;
            else
              rState      <= ST_WAIT_SS_HIGH;  -- abortar
            end if;
          else
            final_reg <= shift_reg;
            rState    <= ST_WAIT_SS_HIGH;
          end if;

        when ST_WAIT_SS_HIGH =>
          if SS_sync2='1' then
            rState <= ST_IDLE;
          end if;
      end case;
    end if;
  end process;

end architecture Behavioral;
