Target			=	my_design

SimFile			=	$(addprefix V,$(Target))

.PHONY: all
all: $(Target)

obj_dir/$(SimFile).cpp: $(Target).v
	verilator -Wall -cc $<

obj_dir/$(SimFile)__ALL.a: obj_dir/$(SimFile).cpp
	make -C obj_dir -f $(SimFile).mk

$(Target): $(Target).cpp obj_dir/$(SimFile)__ALL.a
	g++ -std=c++11	-I obj_dir														\
		-I/opt/homebrew/Cellar/verilator/4.110/share/verilator/include/				\
		/opt/homebrew/Cellar/verilator/4.110/share/verilator/include/verilated.cpp	\
		$^																			\
		-o $(Target)

.PHONY: clean
clean:
	rm -rf obj_dir/ $(Target)
