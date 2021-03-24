#include <stdio.h>
#include <stdlib.h>
#include "Vmy_design.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

void tick(int tickcount, Vmy_design *tb, VerilatedVcdC* tfp)
{
	tb->eval();
	if (tfp) tfp->dump(tickcount * 10 - 2);
	tb->i_clk = 1;
	tb->eval();
	if (tfp) tfp->dump(tickcount * 10);
	tb->i_clk = 0;
	tb->eval(); 
	if (tfp) {
		tfp->dump(tickcount * 10 + 5);
		tfp->flush();
	}
}

int main (int argc, char ** argv)
{
	int last_led;
	unsigned tickcount = 0;


	Verilated::commandArgs(argc, argv);

	Vmy_design * tb = new Vmy_design;

	Verilated::traceEverOn(true);
	VerilatedVcdC* tfp = new VerilatedVcdC;
	tb->trace(tfp,99);
	tfp->open("my_design.vcd");

	last_led = tb->o_led;
	for (int k=0; k<(1<<10); k++){
		tick(++tickcount, tb, tfp);

		if (last_led != tb->o_led){
			printf("k = %7d, ", k);
			printf("led = %02x:", tb->o_led);
			for(int j=0; j<8; j++) {
				if(tb->o_led & (1<<j))
					printf("O");
				else
					printf("-");
			} printf("\n");
		} last_led = tb->o_led;
	}
}
