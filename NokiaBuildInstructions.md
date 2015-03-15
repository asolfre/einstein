# Building Einstein for the Nokia Internet Tablet on MacOS X #

To build Nokia binaries, you need a cross compiler. The previous method was to use the official Maemo SDK (scratchbox compilers) under Linux. The trick was to pass `-I` and `-L` options to the compilers or run them inside the scratchbox chroot (but in this case, you need to put Jam in the chroot). I did not find this very convenient, especially considering that I had to run Linux inside VMWare Fusion...

You can now directly build compatible cross compilers with MacPorts.

  1. Install [MacPorts](http://www.macports.org/)
  1. Install the cross compiler with:
```
sudo port install arm-none-linux-gnueabi-gcc
```
  1. Get K with cvs and compile it with `jam -starget=nokia2006`
  1. Get Einstein with subversion and compile it with `jam -starget=nokia2006 -sK=<path_to_K> -sjittarget=GENERIC`

You can find more details about the compilation process in the general BuildInstructions.

## Notes ##

The default JIT Target (ARMLE) doesn't work  yet. It compiles, but then Einstein crashes. This is why you have to mention `-sjittarget=GENERIC` in the command line.

I believe that the Nokia 800 with OS2007 has a different version of libXau. It's now libXau.so.6 instead of libXau.so.0. The above method will compile against libXau.so.0 (which I directly copied from a Nokia 770 with OS2006), and therefore the binary will not run. I would be grateful if someone with a Nokia 800 and OS2007 could check that and possibly fix the problem by either:
  1. Create a specific nokia2007 target with the new libXau
  1. or try to use -L instead, so that the binary will run on both platforms and dynamically choose the proper binary.