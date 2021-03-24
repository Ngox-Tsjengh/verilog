Target			=	my_design
SimFile			=	$(addprefix V,$(Target))

VERILATOR=verilator
VERILATOR_ROOT ?= $(shell bash -c 'verilator -V|grep VERILATOR_ROOT | head -1 | sed -e "s/^.*=\s*//"')
VINC := $(VERILATOR_ROOT)/include

.PHONY: all av
all: $(Target)

obj_dir/$(SimFile).cpp: $(Target).v
	$(VERILATOR) --trace -Wall -cc $<

obj_dir/$(SimFile)__ALL.a: obj_dir/$(SimFile).cpp
	make -C obj_dir -f $(SimFile).mk

$(Target): $(Target).cpp obj_dir/$(SimFile)__ALL.a
	g++ -std=c++11	-I obj_dir		\
		-I $(VINC)					\
		$(VINC)/verilated.cpp       \
		$(VINC)/verilated_vcd_c.cpp \
		$^							\
		-o $(Target)

wave: $(Target)
	$(shell ./$(Target))
	$(shell /Applications/gtkwave.app/Contents/Resources/bin/gtkwave $(Target).vcd)

.PHONY: clean
clean:
	rm -rf obj_dir/ $(Target) $(Target).vcd
