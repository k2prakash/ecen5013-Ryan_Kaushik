#VARIABLE DEFINITIONS (these act as compile time flags/swithches, defaults are given where appropriate)
CC := gcc
CFLAGS := -Wall -g
target := host


#TARGET SPECIFIC VARIABLES (these will be used by the compile time switches)
ifeq ($(target),bbb)
CC := arm-linux-gnueabi-gcc
include sources.mk
else ifeq ($(target),frdm)
CC := arm-none-eabi-gcc
override frdmflag := --specs=nosys.specs
include sources.mk
else
CC := gcc
target := host
include sources.mk
override run := @./$(bpaths)
endif


#MAKEFILE INCLUDES (this file contains a list of files, directories and paths for the build system)
include sources.mk


#DEFAULT GOAL (just build an image for the specific target)
all: preprocess asm-file compile-all build-lib build


#PHONY TARGETS (also list here are dependencies of these targets)
.PHONY :all preprocess asm-file compile-all build upload clean build-lib
preprocess : $(ifiles)
$(ifiles) : $(cfiles) | $(idir)
	$(CC) $< $(CFLAGS) -E -o $(idir)/$@
$(idir) :
	@mkdir -p $(idir)
	@echo "building preprocessed output"

asm-file : $(sfiles)
$(sfiles) : $(cfiles) | $(sdir)
	$(CC) $< $(CFLAGS) -S -o $(sdir)/$@
$(sdir) :
	@mkdir -p $(sdir)
	@echo "building assembly output"

compile-all	: $(ofiles)
$(ofiles) : $(cfiles) | $(odir)
	$(CC) $< $(CFLAGS) -c -o $(odir)/$@
$(odir) :
	@mkdir -p $(odir)
	@echo "building object file output"

build : $(bfiles)
$(bfiles) : $(cfiles) | $(bdir)
	$(CC) $^ $(frdmflag) $(CFLAGS) -o $(bdir)/$@
	@$(run)
$(bdir) :
	@mkdir -p $(bdir)
	@echo "building image file"

upload : 
	
clean :
	@rm -f -r *.o *.d *.a *.S *.map *.out *.i build #cleans root and deletes build
	@find . -name "*.o" -type f -delete #cleans objs from src dir if any
	@echo "cleaning up the build system"
	
build-lib : $(afiles)
$(afiles) : $(cfiles) | $(adir)
	$(CC) -shared $^ $(CFLAGS) -fpic -o $(adir)/$@
$(adir) :
	@mkdir -p $(adir)
	@echo "building shared library"

$(cfiles) : $(hfiles)

