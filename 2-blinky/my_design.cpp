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
	Verilated::commandArgs(argc, argv);

	Vmy_design * tb = new Vmy_design;

	unsigned tickcount = 0;
	Verilated::traceEverOn(true);
	VerilatedVcdC* tfp = new VerilatedVcdC;
	tb->trace(tfp,99);
	tfp->open("my_design.vcd");


	int last_led;

	for (int k=0; k<(1<<20); k++){
		tick(++tickcount, tb, tfp);

		// Now let's print our results
		if (last_led != tb->o_led){
			printf("k = %7d, ", k);
			printf("led = %d\n", tb->o_led);
		} last_led = tb->o_led;
	}
}
