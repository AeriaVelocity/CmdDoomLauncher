# Command Doom Launcher
### A launcher for Doom for the command line. Written in straight up C (which makes this my first C program ever!)

> Note: Well, I have no idea how the hell to finish this.
> Guess it's my fault for wanting to use C.

## Configuration
On Windows, the default IWAD path is `C:\Users\<username>\Documents`, and on other OSes, it's `/usr/share/games/doom`.

You can change this by editing `config.h` (`config.win.h` on Windows).

## Compiling

All you need is `gcc`.
```
gcc -o cdl main.c
```
On Windows with MinGW:
```
gcc -o cdl.exe main.c
```
