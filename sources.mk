#VARIABLE DEFINITIONS

#source and includes
INCDIR = include
SRCDIR = src
LIBDIR = lib
#build outputs
BLDDIR = build
OBJDIR = $(BLDDIR)/$(ARC)/objects
ASMDIR = $(BLDDIR)/$(ARC)/assembly
PPRDIR = $(BLDDIR)/$(ARC)/preprocessor
EXEDIR = $(BLDDIR)/$(ARC)/bin
#lists of includes, source and object files
INC = $(addprefix $(INCDIR)/, project1.h memory.h data.h)
SRC = $(addprefix $(SRCDIR)/, main.c project1.c memory.c data.c)
OBJ = $(addprefix $(OBJDIR)/, main.o project1.o memory.o data.o)
OUTPUT = project
