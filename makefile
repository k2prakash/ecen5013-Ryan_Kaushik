#VARIABLE DEFINITIONS
CFLAGS :=
override frdmflag :=
platform := host
CC := gcc
override run :=
BBB_IP :=10.38.47.143

#TARGET SPECIFIC VARIABLES
ifeq ($(platform),bbb)
CC := arm-linux-gnueabi-gcc
platform := bbb
else ifeq ($(platform),frdm)
CC := arm-none-eabi-gcc
override frdmflag := --specs=nosys.specs
platform := frdm
else
CC := gcc
platform := host
override run := @./build/host/bin/project
endif


#MAKEFILE INCLUDES (use -include to supress search warnings)
include sources.mk


#DEFAULT GOAL
all: preprocess asm-file compile-all build


#PHONY TARGETS
.PHONY :all asm-file compile-all build upload clean build-lib
preprocess : | $(ppr)
$(ppr) : $(src) | $(idir)
	@$(CC) $< $(CFLAGS) -E -o $(idir)/$@
$(idir) :
	@mkdir -p $(idir)
	echo "building preprocessed output"


asm-file : | $(asm)
$(asm) : $(src) | $(sdir)
	@$(CC) $< $(CFLAGS) -S -o $(sdir)/$@
$(sdir) :
	@mkdir -p $(sdir)
	echo "building assembly output"


compile-all	: | $(obj)
$(obj) : $(src) | $(odir)
	@$(CC) $< $(CFLAGS) -c -o $(odir)/$@
$(odir) :
	@mkdir -p $(odir)
	echo "build object file output"


build : $(src) | $(bdir)
	@$(CC) $^ $(frdmflag) $(CFLAGS) -o $(bdir)/project
	$(run)
$(bdir) :
	@mkdir -p $(bdir)
	echo "building image file"


upload :
	@./scp_remote.sh $(BBB_IP)
	
clean :
	@rm -f -r *.o *.d *.a *.S *.map *.out *.i build #cleans root and deletes build
	@find . -name "*.o" -type f -delete #cleans objs from src dir if any
	@echo "cleaning up the build system"
	
build-lib : $(src) | $(libdir)
	$(CC) -shared $(cfiles) -fpic -o $(libfiles)
$(libdir) :
	@mkdir -p $(libdir)
	echo "build shared library"

	
.NORPARALLEL :
.ONESHELL :

