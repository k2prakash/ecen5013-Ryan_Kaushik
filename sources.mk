#VARIABLE DEFINITIONS

#source and includes
VPATH := src include sdir odir idir
cdir := src
bdir := build/$(platform)/bin
odir := build/$(platform)/obj
sdir := build/$(platform)/asm
idir := build/$(platform)/ppr
#lists of includes, source and object files
inc := project_1.h memory.h data.h
src := main.c $(inc:.h=.c)
cfiles := $(addprefix $(idir)/,$(src))
obj := $(src:.c=.o)
ofiles := $(addprefix $(idir)/,$(obj))
asm := $(src:.c=.S)
sfiles := $(addprefix $(idir)/,$(asm))
ppr := $(src:.c=.i)
ifiles := $(addprefix $(idir)/,$(ppr))

#the  final output file name
output := project
