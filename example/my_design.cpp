#include "Vmy_design.h"
#include "verilated.h"

int main(int argc, char** argv, char** env) {
	VerilatedContext* contextp = new VerilatedContext;
	contextp -> commandArgs(argc, argv);

	Vmy_design* top = new Vmy_design{contextp};
	
	while (!contextp->gotFinish()) {top->eval();}

	delete top;
	delete contextp;
	return 0;
}
