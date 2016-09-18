#VARIABLE DEFINITIONS
CFLAGS :=
#TARGET SPECIFIC VARIABLES
host : CC := gcc
host : PLFM := host
bbb : CC := arm-linux-gnueabi-gcc
bbb : PLFM := bbb
frdm : CC := arm-none-eabi-gcc
frdm : PLFM := frdm


#MAKEFILE INCLUDES (use -include to supress search warnings)
include sources.mk


#DEFAULT GOAL (only build host as default. To call another plateform just specify bbb or frdm)
all: host
.PHONY : all host bbb frdm

host : $(src)
	mkdir -p $(BLDDIR)/$(PLFM)/bin
	$(CC) $(CFLAGS) $^ -o $(BLDDIR)/$(PLFM)/bin/project
	./$(BLDDIR)/$(PLFM)/bin/$(OUTPUT)

bbb : $(src)
	mkdir -p $(BLDDIR)/$(PLFM)/bin
	$(CC) $(CFLAGS) $^ -o $(BLDDIR)/$(PLFM)/bin/project

frdm : $(src)
	mkdir -p $(BLDDIR)/$(PLFM)/bin
	$(CC) $(CFLAGS) --specs=nosys.specs $^ -o $(BLDDIR)/$(PLFM)/bin/project

	
#PHONY TARGETS
.PHONY : preprocess asm-file %.o compile-all build upload clean build-lib
preprocess :
	mkdir -p $(BLDDIR)/$(PLFM)/preprocess
	$(CC) -E $(SRC) -o $(PPR)
asm-file :
	mkdir -p $(BLDDIR)/$(PLFM)/assembly
	$(CC) -S $(SRC)
%.o :
	mkdir -p $(BLDDIR)/$(PLFM)/object
	$(CC) -c $(SRC)
compile-all :
	mkdir -p $(OBJDIR)
	$(CC) -c $(SRC)
build :
	mkdir -p $(EXEDIR)
	$(CC) $(SRC) -o $(EXEDIR)
upload :
	
clean :
	rm -f -r *.o *.d *.a *.S *.map *.out *.i build #cleans root and deletes build
	find . -name "*.o" -type f -delete #cleans objs from src dir if any
build-lib :
	mkdir -p $(LIBDIR)
	$(CC) -shared $(SRC) $(LIBDIR)/libproject1.a
.NORPARALLEL :

