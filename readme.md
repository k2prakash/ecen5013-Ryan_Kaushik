README FILE

Hello, and welcome to the best repository in the world!
To get started you'll want to read up on the build
specific options in makefile_readme.md. That has most
of the information you'd want regarding make and how to
use it here.

Also take a look at the content.md file which list the
structure of the contents of ths repo.

This project is fairly lightweigth, so there isn't much
to see... yet, but that will change.

All source code is written in a lightweight form of c
called embedded c, which is designed to be run on
embedded systems.

We have three main targets to build, they include the
host VM, Ubuntu 16 favor, the BeagleBone Black and
the Freedom Freescale development boards. The source
code with which we are developing is intended to by as
architecture independent as possible. Meaning the source
code doesn't have a lot of preprocessed modifications to
build a certain way. There is one exception to that,
printf statements on the freedom.

All source code can also be found in one convenient
location - the src directory on the root. Also the 
source.mk file contains a list, amoung other things, of
all the source c files. This is use by make to build the 
targets. Includes can be found in the include directory.
All other files are in the root directory, including this
readme.

When building targetsthrough make, make places build
output content in ./build. From there is organizes the
output depending on the target platform and the output
type. This keeps all files localized to a certain make
target.

If you need to clean the repo, make can handle that. Just
call make clean and your repo will no longer have an local
build output content. This means the outputs will need to
be generated again, if you intent to use them.

The is a bash script that performs external commands from
make. This file is in the root and is called scp_remote, 
likewise IPListfiles is used by make. These can be
ignored in most cases, by the user.

The other files contain additional information you may want
to review before delving into this extensive build system.
We suggest you readit from copy to copy, about 1-2 pages
worth.

By
Ryan Haun
Kaushik Prakash
