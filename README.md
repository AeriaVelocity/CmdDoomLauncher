# Command Doom Launcher
### A launcher for Doom for the command line. Written in straight up C (which makes this my first C program ever!)

> Note: This program is currently unfinished.

## Configuration
On Windows, the default IWAD path is `C:\Users\<username>\Documents`, and on other OSes, it's `/usr/share/games/doom`.

You can change this by editing `config.h` (`config.win.h` on Windows).

## Compiling

All you need is `gcc`.
```
gcc -o cdl main.c
```
On Windows:
```
gcc -o cdl.exe main.c
```
