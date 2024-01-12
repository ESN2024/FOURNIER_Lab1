-- top_level.vhd

-- Generated using ACDS version 18.1 625

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity top_level is
	port (
		clk_clk                          : in  std_logic                    := '0'; --                       clk.clk
		pio_0_external_connection_export : out std_logic_vector(7 downto 0);        -- pio_0_external_connection.export
		reset_reset_n                    : in  std_logic                    := '0'  --                     reset.reset_n
	);
end entity top_level;

architecture rtl of top_level is

	component chenillard is
		port (
			clk_clk                          : in  std_logic                    := 'X'; -- clk
			pio_0_external_connection_export : out std_logic_vector(7 downto 0);        -- export
			reset_reset_n                    : in  std_logic                    := 'X'  -- reset_n
		);
	end component chenillard;
	
begin

	u0 : component chenillard
		port map (
			clk_clk                          => clk_clk,                          --                       clk.clk
			pio_0_external_connection_export => pio_0_external_connection_export, -- pio_0_external_connection.export
			reset_reset_n                    => reset_reset_n                     --                     reset.reset_n
		);
end architecture;