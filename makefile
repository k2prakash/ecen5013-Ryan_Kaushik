#Including variable to gather source files
#can also use -include or sinclude
include sources.mk


#VARIABLE DEFINITIONS - see chapter 6



#DEFAULT GOAL - add auguments to specify a different default goal, see section 9.2
#or with the .DEFAULT_GOAL special variable see section 6.14
#use a :: to always remake
project : $(OBJ)
	gcc -o project $(OBJ)
	
	
#EXPLICIT RULES



#IMPLICIT RULES - see chapter 10
main.o :
project1.o : project1.h
memory.o : memory.h
data.o : data.h


#PHONY TARGETS - see sections 4.5 and 5.5
.PHONY : clean
clean :
	rm project $(OBJ)





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
