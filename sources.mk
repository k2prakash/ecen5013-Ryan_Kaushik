#VARIABLE DEFINITIONS

#source and includes
VPATH := src include
INCDIR := include
SRCDIR := src
#build outputs
BLDDIR := build
OBJDIR := $(BLDDIR)/$(PLFM)/object
ASMDIR := $(BLDDIR)/$(PLFM)/assembly
PPRDIR := $(BLDDIR)/$(PLFM)/preprocess
BINDIR := $(BLDDIR)/$(PLFM)/bin
LIBDIR := $(BLDDIR)/$(PLFM)/lib
#lists of includes, source and object files
inc := project_1.h memory.h data.h
src := main.c $(inc:.h=.c)
obj := $(src:.c=.o)
asm := $(src:.c=.S)
ppr := $(src:.c=.i)
#similar to the above but also has the path appended
INC := $(addprefix $(INCDIR)/, $(inc))
SRC := $(addprefix $(SRCDIR)/, $(src))
OBJ := $(addprefix $(OBJDIR)/, $(obj))
ASM := $(addprefix $(ASMDIR)/, $(asm))
PPR := $(addprefix $(PPRDIR)/, $(ppr))
#the  final output file name
OUTPUT := project
