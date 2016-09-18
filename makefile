#VARIABLE DEFINITIONS
CFLAGS :=
override FRDMFLAG :=
PLATFORM := host
CC := gcc
override RUN :=


#TARGET SPECIFIC VARIABLES
ifeq ($(PLATFORM),bbb)
CC := arm-linux-gnueabi-gcc
PLATFORM := bbb
else ifeq ($(PLATFORM),frdm)
CC := arm-none-eabi-gcc
override FRDMFLAG := --specs=nosys.specs
PLATFORM := frdm
else
CC := gcc
PLATFORM := host
override RUN := @./build/host/bin/project
endif


#MAKEFILE INCLUDES (use -include to supress search warnings)
include sources.mk


#CANNED RECIPES
define makedir =
@mkdir -p $(BLDDIR)/$(PLATFORM)/bin
@mkdir -p $(BLDDIR)/$(PLATFORM)/object
@mkdir -p $(BLDDIR)/$(PLATFORM)/asm
@mkdir -p $(BLDDIR)/$(PLATFORM)/preprocced
endef


#FUNCTIONS
preprocess

#DEFAULT GOAL
all: build


#PHONY TARGETS
.PHONY :all preprocess asm-file %.o compile-all build upload clean build-lib
preprocess : $(ppr)
	$(makedir)
	$(CC) -E $(src)
	
asm-file :
	$(makedir)
	$(CC) -S $(src)
	
%.o :
	$(makedir)
	$(CC) -c $(src)
	
compile-all :
	$(makedir)
	$(CC) -c $(src)
	
build : $(src)
	$(makedir)
	$(CC) $(CFLAGS) $(FRDMFLAG) $^ -o $(BLDDIR)/$(PLATFORM)/bin/project
	$(RUN)
	
upload :
	
clean :
	rm -f -r *.o *.d *.a *.S *.map *.out *.i build #cleans root and deletes build
	find . -name "*.o" -type f -delete #cleans objs from src dir if any
	
build-lib :
	mkdir -p $(LIBDIR)
	$(CC) -shared $(SRC) $(LIBDIR)/libproject1.a
	

	
.NORPARALLEL :

