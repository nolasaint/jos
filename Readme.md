# JOS, a unix-like OS

## Foreword
The framework for this operating system is provided by the wonderful course MIT 6.828. Check out the course overview [here](https://pdos.csail.mit.edu/6.828/2016/overview.html).

Thank you to the wonderful instructors, TAs, and other individuals who have made this course possible (past and present).

## About

JOS is a unix-like operating system implemented in an exokernel style.

This implementation is far from perfect, but serves as a great tool to learn about the challenges, practices, and considerations that go into making an operating system.

This repository is organized into a number of conceptual branches which are described later in this document.

## Usage

A makefile is provided with this repository to simplify the building and testing processes.

Note that a virtual machine, or more practically an emulator, must be used for testing JOS without booting from a physical disk. The makefile has been configured to use the [QEMU emulator](http://wiki.qemu.org/Main_Page).

Check out the [tools page]() on the MIT 6.828 course website to get the necessary tools to set up a testing environment.

This implementation of JOS was developed on a 32-bit Ubuntu VM, using QEMU to emulate a PC for JOS to boot on.

## Build

To build for QEMU and boot the kernel, run this command from the root directory:

    $ make qemu

If no serial video display is connected, build for qemu no-graphics mode:

    $ make qemu-nox

This is useful when running QEMU on a virtual machine via ssh.

### Debugging with GDB

A build target has been provided for debugging JOS in GDB:

    $ make qemu-gdb

Or:

    $ make qemu-nox-gdb

Then, in a separate terminal:

    $ make gdb

This will build JOS for QEMU, configuring the emulator to hook into GDB.

### Testing

Once user environments are implemented, this section will be updated.

## Branches

There are 3 primary branches in this repository:

* `master`
* `development`
* `labs/`

### master

The master branch contains only the source and build tools for the most up-to-date JOS revision. Note that the makefile still contains all targets and as such, builds such as `make grade LAB=1` will fail due to a lack of grading scripts.

### development

The development branch contains the source, build tools, and testing tools for the most up-to-date JOS revision.

The development branch is occasionally merged into the master branch once major features are deemed fully implemented.

### labs/*

The lab branches contain the solutions to the lab exercises provided by MIT 6.828, which serves as the framework on which JOS is implemented.

## Changelog

* **21 December 2016**
 * implemented lab 1
