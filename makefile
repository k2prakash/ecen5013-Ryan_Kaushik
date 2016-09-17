#VARIABLE DEFINITIONS
CC = gcc
CDEFS =
CFLAGS =
PLFM = host


#MAKEFILE INCLUDES (use -include to supress search warnings)
include sources.mk


#DEFAULT GOAL
all : host bbb frdm
.PHONY : all host bbb frdm

PLFM = host
host : project

PLFM = bbb
bbb : project

PLFM = frdm
frdm : project

project : $(SRC)
	mkdir -p $(BLDDIR)/$(PLFM)/bin
	$(CC) -c $(CFLAGS) $^ -o $(BINDIR)/project
	./$(BINDIR)/$(OUTPUT)


#PHONY TARGETS
.PHONY : preprocess asm-file %.o compile-all build upload clean build-lib
preprocess :
	mkdir -p $(PPRDIR)
	$(CC) -E $(SRC)
asm-file :
	mkdir -p $(ASMDIR)
	$(CC) -S $(SRC)
%.o :
	mkdir -p $(OBJDIR)
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

