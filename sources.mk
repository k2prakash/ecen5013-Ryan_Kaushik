#VARIABLE DEFINITIONS

#inclue, source and build specific directories
hdir := include
cdir := src
tdir := build/$(target)
bdir := $(tdir)/bin
odir := $(tdir)/object
idir := $(tdir)/preprocessed
sdir := $(tdir)/assembly
adir := $(tdir)/lib


#adding implicit search for any files on these directories
VPATH := $(hdir) $(cdir) $(bdir) $(odir) $(sdir) $(adir) $(idir)


#list file name (file name does not include the file directory), only have one bfiles
hfiles := project_1.h memory.h data.h
cfiles := main.c project_1.c memory.c data.c
bfiles := project
ofiles := $(cfiles:.c=.o)
ifiles := $(cfiles:.c=.i)
sfiles := $(cfiles:.c=.S)
afiles := libproject1.a


#list file path (file path is file directory and file name)
hpaths := $(addprefix $(hdir)/,$(hfiles))
cpaths := $(addprefix $(cdir)/,$(cfiles))
bpaths := $(addprefix $(bdir)/,$(bfiles))
opaths := $(addprefix $(odir)/,$(ofiles))
ipaths := $(addprefix $(idir)/,$(ifiles))
spaths := $(addprefix $(sdir)/,$(sfiles))
apaths := $(addprefix $(adir)/,$(afiles))
