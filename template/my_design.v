`default_nettype none

module my_design(i_sw, o_led);
	input wire 		[8:0]	i_sw;
	output wire		[8:0]	o_led;

	wire [8:0]		w_internel;

	assign	w_internel = 9'h87;

	assign o_led = i_sw ^ w_internel;
endmodule
