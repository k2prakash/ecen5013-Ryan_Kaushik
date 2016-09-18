#VARIABLE DEFINITIONS

#inclue, source and build specific directories
hdir := include
cdir := src
tdir := build/$(target)
bdir := $(tdir)/bin
odir := $(tdir)/obj
sdir := $(tdir)/asm
idir := $(tdir)/ppr
adir := $(tdir)/lib


#adding implicit search for any files on these directories
VPATH := $(hdir) $(cdir) $(bdir) $(odir) $(sdir) $(idir) $(adir)


#list file name (file name does not include the file directory), only have one bfiles
hfiles := project_1.h memory.h data.h
cfiles := main.c project_1.c memory.c data.c
bfiles := project
ofiles := $(cfiles:.c=.o)
sfiles := $(cfiles:.c=.S)
ifiles := $(cfiles:.c=.i)
afiles := libproject1.a


#list file path (file path is file directory and file name)
hpaths := $(addprefix $(hdir)/,$(hfiles))
cpaths := $(addprefix $(cdir)/,$(cfiles))
bpaths := $(addprefix $(bdir)/,$(bfiles))
opaths := $(addprefix $(odir)/,$(ofiles))
spaths := $(addprefix $(sdir)/,$(sfiles))
ipaths := $(addprefix $(idir)/,$(ifiles))
apaths := $(addprefix $(adir)/,$(afiles))


