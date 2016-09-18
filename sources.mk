#VARIABLE DEFINITIONS

#source and includes
VPATH := src include sdir odir idir
cdir := src
libdir := build/$(platform)/lib
bdir := build/$(platform)/bin
odir := build/$(platform)/obj
sdir := build/$(platform)/asm
idir := build/$(platform)/ppr
#lists of includes, source and object files
inc := project_1.h memory.h data.h
src := main.c $(inc:.h=.c)
cfiles := $(addprefix $(cdir)/,$(src))
obj := $(src:.c=.o)
ofiles := $(addprefix $(odir)/,$(obj))
asm := $(src:.c=.S)
sfiles := $(addprefix $(adir)/,$(asm))
ppr := $(src:.c=.i)
ifiles := $(addprefix $(idir)/,$(ppr))
libfiles := $(addprefix $(libdir)/,libproject1.a)

#the  final output file name
output := project
