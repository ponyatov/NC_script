# NC_script
### CNC script language

(c) Dmitry Ponyatov <<dponyatov@gmail.com>> , GNU LesserGPL

github: https://github.com/ponyatov/NC_script

### Goals

Infix processing of regular CNC programs in ISO 6983-1:2009 and HAAS variants
Extends ISO7 (G-code) programming languages with extra functionality.

### Requirements

Program build requires GNU GCC toolchain installed (MinGW for win32):
- g++ compiler
- make
- flex
- bison

### Samples used from

http://www.helmancnc.com/haas-cnc/

### Principles

- all .nc code will be bypassed as is
- # comments will be removed from target.nc
- all magic happens in {brackets}:
+ commands will be reformatted in form compatible with selected .machine

