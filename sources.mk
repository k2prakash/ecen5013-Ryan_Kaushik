#VARIABLE DEFINITIONS

#source and includes
VPATH = src include
INCDIR = include
SRCDIR = src
#build outputs
BLDDIR = build
OBJDIR = $(BLDDIR)/$(PLFM)/object
ASMDIR = $(BLDDIR)/$(PLFM)/assembly
PPRDIR = $(BLDDIR)/$(PLFM)/preprocessor
BINDIR = $(BLDDIR)/$(PLFM)/bin
LIBDIR = $(BLDDIR)/$(PLFM)/lib
#lists of includes, source and object files
INC = $(addprefix $(INCDIR)/, project1.h memory.h data.h)
SRC = $(addprefix $(SRCDIR)/, main.c project_1.c memory.c data.c)
OBJ = $(addprefix $(OBJDIR)/, main.o project_1.o memory.o data.o)
ASM = $(addprefix $(ASMDIR)/, main.a project_1.S memory.S data.S)
PPR = $(addprefix $(PPRDIR)/, main.c project_1.c memory.c data.c)
OUTPUT = project
