#VARIABLE DEFINITIONS
INCDIR = include
SRCDIR = src
LIBDIR = lib
BLDDIR = build
OBJDIR = $(BLDDIR)/objects
ASMDIR = $(BLDDIR)/assembly
PPRDIR = $(BLDDIR)/preprocessor
include sources.mk
CC = gcc #gcc, arm-linux-gnueabihf.gcc, arm-linux-gnueabi.gcc, arm-none-eabi-gcc 
CDEFS = cdefs
COPT = -std=c99
CFLAGS = -o  #-O0 -g
LIBS = libs
OUTPUT = $(BLDDIR)/project


#DEFAULT GOAL
project :
	mkdir -p $(BLDDIR)
	$(CC) $(SRC) $(CFLAGS) $(OUTPUT)
	./$(BLDDIR)/project
	

	
	
#RULES
main.o :

project1.o : project.c project1.h
	$(CC) $(CFLAGS)
memory.o : memory.h
data.o : data.h


#PHONY TARGETS
.PHONY : clean
clean :
	rm -f *.o *.d *.a
	rm build/project
	rmdir build





#INCLUDE_DIRS =
#LIB_DIRS =
#CC=gcc

#CDEFS=
#CFLAGS= -O0 -g $(INCLUDE_DIRS) $(CDEFS)
#LIBS=

#HFILES=
#CFILES= feasibility_tests.c

#SRCS= ${HFILES} ${CFILES}
#OBJS= ${CFILES:.c=.o}

#all:    feasibility_tests

#clean:
#       -rm -f *.o *.d
#       -rm -f feasibility_tests

#feasibility_tests: feasibility_tests.o
#       $(CC) $(LDFLAGS) $(CFLAGS) -o $@ $@.o -lm

#depend:

#.c.o:
#       $(CC) $(CFLAGS) -c $<
