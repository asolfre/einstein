## Overview ##

Einstein has a built-in monitor that allows you to:

  * pause and resume Newton emulation
  * view disassembly, CPU registers, MMU information, and memory
  * set breakpoints
  * and more!

Currently the monitor is available in command-line and Mac OS X builds of Einstein.  In the Mac OS X version, it can be accessed by choosing Window > Monitor.

## Commands ##

  * **stop** stops the emulator, displaying registers and code at the current pc
  * **run** (or **g**) resumes a stopped emulator
  * **mmu** displays MMU status
  * **mmu addr** resolve virtual address addr to a physical address
  * **step** steps one instruction
  * **trace** (or **t**)
  * **mr**
  * **break addr** (or **bp addr**) set a breakpoint at the given address
  * **bc addr** clear the breakpoint at addr
  * **dl Paddr** display from a physical address
  * **dl addr** display from a virtual address
  * **dm addr** display memory at virtual address
  * **dm Paddr** display memory at physical address
  * **dm begin-end** display memory within range of virtual addresses
  * **dm Pbegin-end** display memory within range of physical addresses
  * **pc=n** set pc to n
  * **sl addr val** store value at virtual address
  * **sl Paddr val** store value at physical address
  * **rX=n** set register X (0-15) to n
  * **raise n** raise interrupt #n
  * **gpio n** raise GPIO n
  * **watch n addr**
  * **enable log** log to file on disk
  * **disable log** stop logging to file on disk