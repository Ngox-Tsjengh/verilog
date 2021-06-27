`default_nettype none

module my_design(i_clk, o_led);
	input wire 			i_clk;
	output reg [7:0]	o_led;

	reg		[4-1:0]	led_index;		//Finite State
	initial led_index = 0;

	always @(posedge i_clk) begin
		if (led_index > 4'd13) led_index <= 0;
		else led_index <= led_index + 1'b1;
	end
	
	always @(posedge i_clk) begin
		case (led_index)
			4'h0:	o_led <= 8'h01; 
			4'h1:	o_led <= 8'h02; 
			4'h2:	o_led <= 8'h04; 
			4'h3:	o_led <= 8'h08; 
			4'h4:	o_led <= 8'h10; 
			4'h5:	o_led <= 8'h20; 
			4'h6:	o_led <= 8'h40; 
			4'h7:	o_led <= 8'h80; 
			4'h8:	o_led <= 8'h40; 
			4'h9:	o_led <= 8'h20; 
			4'ha:	o_led <= 8'h10; 
			4'hb:	o_led <= 8'h08; 
			4'hc:	o_led <= 8'h04; 
			4'hd:	o_led <= 8'h02; 
			default:o_led <= 8'h01;
		endcase
	end
endmodule

`ifdef FORMAL
	always @(*) begin
		assert (led_index < 4'd13)
	end
		
	reg	f_valid_output;

	always @(*)
	begin
		// Determining if the output is valid or not is a rather
		// complex task--unusual for a typical assertion.  Here, we'll
		// use f_valid_output and a series of _blocking_ statements
		// to determine if the output is one of our valid outputs.
		f_valid_output = 0;

		case(o_led)
		8'h01: f_valid_output = 1'b1;
		8'h02: f_valid_output = 1'b1;
		8'h04: f_valid_output = 1'b1;
		8'h08: f_valid_output = 1'b1;
		8'h10: f_valid_output = 1'b1;
		8'h20: f_valid_output = 1'b1;
		8'h40: f_valid_output = 1'b1;
		8'h80: f_valid_output = 1'b1;
		endcase

		assert(f_valid_output);

		// SV supports a $onehot function which we could've also used
		// depending upon your version of Yosys.  This function will
		// be true if one, and only one, bit in the argument is true.
		// Hence we might have said
		// assert($onehot(o_led));
		// and avoided this case statement entirely.
	end
`endif
