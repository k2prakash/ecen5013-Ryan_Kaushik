#VARIABLE DEFINITIONS (these act as compile time flags/swithches, defaults are given where appropriate)
CC            := gcc
CSTD          := -std=c99
CFLAGS        := -Wall -g -O0 
DFLAGS        := -f #Common options -a -f -p -P -h -x -d -D -S -s -g -e -G -t -T -r -R -v -i -H
target        := host #host, bbb, frdm
BBB_IP        := 192.168.7.2
BBB_USER_NAME := debian #username of os, bbb is usually debian or ubuntu loaded


#TARGET SPECIFIC VARIABLES (these will be used by the compile time switches)
ifeq ($(target),bbb)
CC := arm-linux-gnueabi-gcc
else ifeq ($(target),bbb_ubnt)
CC := arm-linux-gnueabihf-gcc-5
else ifeq ($(target),frdm)
CC := arm-none-eabi-gcc
CFLAGS := -Wall -g -O0 -D FRDM 
override frdmflag := --specs=nosys.specs
else
CC := gcc
target := host
endif

#MAKEFILE INCLUDES (this file contains a list of files, directories and paths for the build system)
include sources.mk


#DEFAULT GOAL (just build an image for the specific target)
all: preprocess asm-file compile-all build-lib build image-size image-dump


#PHONY TARGETS (also list here are dependencies of these targets)
.PHONY :all preprocess asm-file compile-all build upload clean build-lib image-run image-size image-dump


preprocess : $(ifiles)
%.i : %.c | $(idir)
	@echo "building preprocessed output $|/$@"
	@$(CC) $(cdir)/$*.c $(CSTD) $(CFLAGS) -E -o $|/$@
$(idir) :
	@mkdir -p $(idir)


asm-file : $(sfiles)
%.S : %.c | $(sdir)
	@echo "building assembly output $|/$@"
	@$(CC) $(cdir)/$*.c $(CSTD) $(CFLAGS) -S -o $|/$@
$(sdir) :
	@mkdir -p $(sdir)


compile-all	: $(ofiles)
%.o : %.c | $(odir)
	@echo "building object file output $|/$@"
	@$(CC) $(cdir)/$*.c $(CSTD) $(CFLAGS) -c -o $|/$@
$(odir) :
	@mkdir -p $(odir)


build : $(bfiles)
$(bfiles) : $(cfiles) | $(bdir)
	@echo "building image file $|/$@"
	@$(CC) $^ $(CSTD) $(frdmflag) $(CFLAGS) -o $|/$@
	@echo "\n\n"
$(bdir) :
	@mkdir -p $(bdir)


upload :  $(bfiles)
	@echo "scp into $(BBB_IP)";
	scp -r $(bdir) $(BBB_USER_NAME)@$(BBB_IP):$(BBB_OUTPUT_PATH)
	

clean :
	@rm -f -r *.o *.d *.a *.S *.map *.out *.i *.p build #cleans root and deletes build
	@find . -name "*.o" -type f -delete #cleans objs from src dir if any
	@echo "cleaning up the build system"
	
	
image-run : $(bfiles)
	@echo "running image file $(bpaths)\n"
	@./$(bpaths)
	@echo "\n"
	
	
image-size : $(bfiles)
	@echo "sizing image file $(bpaths)\n"
	@size $(bpaths)
	@echo "\n\n"


image-dump : $(bfiles)
	@echo "objdump of image file $(bpaths)\n"
	@objdump $(DFLAGS) $(bpaths)
	@echo "\n"

build-lib : $(afiles)
$(afiles) : $(cfiles) | $(adir)
	@echo "building shared library $|/$@"
	@$(CC) -shared $^ $(CSTD) $(CFLAGS) -fpic -o $|/$@
$(adir) :
	@mkdir -p $(adir)

