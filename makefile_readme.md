Welcom to the readme file for the makefile

Hopefully this document and orient you in working with this
build system using make.

++++++++++++++++
THE MAIN TARGETS
++++++++++++++++

The build system is design to make several targets. Depending
on the desired target you want make to make, you add that as
input to make when calling it.

The main targets are a compile and link operation that will
generate a image file for the intended plateform. These targets
include:

1. host - builds an image for the host using the native gcc compiler
2. bbb - cross-compiles an image for the beaglebone black
3. frdm - cross-compiles an image for the freedom freescale

To invoke one of these targets, simple enter them as input to make,
like so:

make host bbb frdm

or for any single one

make bbb

This will execute the specific target and will neglect the others.
By default the host target is run with no input arguments. This is
defined as the default goal. To run the default goal, simply call,

make

and the host target will build and since the image is for the host
it will also run the image as a check to see what's executing.
The other main tagets do not have this type of validation since the
will run on the respective target plateforms.

These targets create the image files in the build directory, under the
specific plateform in the bin folder. Like so,

build/host/bin/project

Since we need the image files to be called "project" and we need to
build any target specficied at compile time, we need separate
directories to place these images.

++++++++++++++++++
ADDITIONAL TARGETS
++++++++++++++++++

The build system also include additonal targets that can be called
just like the main targets.
