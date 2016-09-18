#VARIABLE DEFINITIONS

#source and includes
VPATH := src include
#build outputs
BLDDIR := build
#lists of includes, source and object files
inc := project_1.h memory.h data.h
src := main.c $(inc:.h=.c)
obj := $(src:.c=.o)
asm := $(src:.c=.S)
ppr := $(src:.c=.i)
#the  final output file name
OUTPUT := project
