# Command Doom Launcher
### A launcher for Doom for the command line. Written in straight up C (which makes this my first C program ever!)

## Prerequisites
You need [GCC](http://gcc.gnu.org). On Windows, get [MinGW](https://osdn.net/projects/mingw/).

## Configuration
If you're not on Windows, the IWAD directory defaults to `/usr/share/games/doom`.

You can change this by editing `config.h` (`config.win.h` on Windows).
> You MUST edit `config.h`/`config.win.h` if you're on Windows or macOS, since there's no predefined place that your IWADs or executables go.

## Downloading and compiling
```
git clone https://github.com/That1M8Head/CmdDoomLauncher
cd CmdDoomLauncher
./build.sh
```

### On Windows
```
git clone https://github.com/That1M8Head/CmdDoomLauncher
cd CmdDoomLauncher
build
```
