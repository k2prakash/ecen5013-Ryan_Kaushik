#VARIABLE DEFINITIONS
CC = gcc#gcc, arm-linux-gnueabihf.gcc, arm-linux-gnueabi.gcc, arm-none-eabi-gcc 
ARC = host#host, bbb, frdm
CDEFS = cdefs
CSTD = -std=c99
CFLAGS = -o #-Wall, -g, -O0, architecture specific flags
LIBS = libs


#MAKEFILE INCLUDES
include sources.mk


#DEFAULT GOAL
project :
	mkdir -p $(EXEDIR)
	$(CC) $(SRC) $(CFLAGS) $(EXEDIR)/$(OUTPUT)	
	./$(EXEDIR)/$(OUTPUT)
	
#RULES
#main.o :
#
#project1.o : project.c project1.h
#	$(CC) $(CFLAGS)
#memory.o : memory.h
#data.o : data.h


#PHONY TARGETS
.PHONY : clean
clean :
	rm -f -r *.o *.d *.a build #cleans root and deletes build
	find . -name "*.o" -type f -delete #cleans objs from src dir if any





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
