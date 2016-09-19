Welcom to the readme file for the makefile

Hopefully this document and orient you in working with this
build system using make.

++++++++++++++++
DEFAULT TARGETS
++++++++++++++++

This build system is intended to have several options, giving the user greater control
of they build setup. When running make without any arguments the default target is
build. The target produces the image file or executable for the default target platform.
The default target platform is host, which is intended for builds performed with a
native compiler.

+++++++++++++++++++
ALTERNATIVE TARGETS
+++++++++++++++++++

If the user wants to run a different target or targets, they simply specifc these targets
on the commandline when called make. For instance, the follow main targets are defined
in the build system.

	1. preprocess
	2. asm-file
	3. compile-all
	4. build
	5. upload
	6. clean
	7. build-lib
	
The Preprocess target simply builds all the preprocessed output from the selected compiler.
The asm-file target builds the all the assembly output stop, compile-all only builds the
object files, build creates an executable/image file to be run on the specified target.
The upload target, compiles if necassary and ships the image off to the beaglebone black,
in some release folder, where it can be executed. Obviously the beaglebone should be
connectedduring this targets execution. The clean target searches for build output files
and purges them from the repository. These files are never recognized by git. All the build
output files will be located in ./build/ within the repos root. The build-lib target
builds an lib/archive file. This file can be linked to other object files. To build a
specifc target just list them off, like so.

	make build asm-file
	
This will compile and link, creating an image file and create assembly output.

++++++++++++++++++
INDIVIDUAL TARGETS
++++++++++++++++++

In addition to the above targets which build all of the output for each of the source files,
the user has the option to specify individual files as targets to build specific ones.
The file name and extension are used to deduce the compilation performed. For instance if
the user want to create an assembly file for memory.c, they just call make with that as the
target.

	make memory.S
	
Any combination of targets may suffice.

	make asm-file data.i memory.o build
	
Each one in turn will be built. Some of these targets are dependant on others but that should'nt
alter how the use calls these targets.

+++++++++++++++++
MAKE ONLY UPDATES
+++++++++++++++++

Part of this build system to designed to ensure no waste occurs. So unnecassary compilations are
ignored when make is run. For instance,

	make build build
	
Will run the build target twice, but on the second run, the process is skipped because the first
pass updated the targets. Unless there was an error in the first build, the second or third build
will never run. That is until the files are deleted. The user can run the

	make clean
	
command to purge their build system of any unwanted files. After calling clean, the other builds
will execute as the target files do not exist.

+++++++++++++++++++++
COMPILE TIME SWITCHES
+++++++++++++++++++++

There are a few compile time flags/switchs the user can specific on the commandline when calling
make. These include,

	1. CSTD
	2. target
	3. CC
	4. CFLAGS
	
In order to use such switch all the user needs to do is set these when calling make, like so.

	make target=bbb CSTD=-std=c99 CC=arm-linux-gnueabi-gcc CFLAGS=-g
	
It's really not necessary to set both the target and the CC, for compile. The user should just
set the target, with is the target platform, not a make target. The available target switches
include,

	1. host
	2. bbb
	3. frdm
	
All necessary compile time flages are automatically set when specifying the target switch.
This is not true when setting the CC, compile swtich. The supported CFLAGS include

	1. -g
	2. -Wall
	3. -O0
	
Target specific flags are taken care of automatically or can be added here. The build system
is intended to be build using the c99 standard. The CSDT switch can be set or ignore.

When building the image file on the host, for the host, a commandline input is used to test
the output of such a file, if it prints to the standard output. This a a good quick confirmation
that the file was built properly and behaves as desired.

+++++++
AUTHORS
+++++++

Ryan Haun
Kaushik Prakash
