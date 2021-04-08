# AmebaArduboyPlaytune

This is a fork of the ArduboyPlaytune library targetting the Realtek RTL8722DM microcontroller, the original source code is maintained in a git repository hosted on [GitHub](https://github.com/) at:

https://github.com/Arduboy/ArduboyPlaytune

## Limitations of this fork

Due to the original Arduboy library targetting the ATmega 32u4 microcontroller, it made extensive use of architecture specific assembly instructions for speed improvements. Efforts were made to convert these instructions back to C/C++ code with equivalent functionality suitable for the RTL8722DM, but not all functionality could be converted.