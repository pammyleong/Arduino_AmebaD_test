AmebaArduboy Library · `1.1.1`
===============

This is a fork of version `1.1.1` of the Arduboy Library, targeting the Realtek RTL8722DM microcontroller.

## About

Arduboy is an open-source hardware platform allowing gamers to easily make and share games using C/C++. The **Arduboy Library** is an open-source library that provides a programming interface for making games and applications that run on an Arduboy.

The Github url for this original Arduboy project is https://github.com/Arduboy/Arduboy.

## Limitations of this fork

Due to the original Arduboy library targetting the ATmega 32u4 microcontroller, it made extensive use of architecture specific assembly instructions for speed improvements. Efforts were made to convert these instructions back to C/C++ code with equivalent functionality suitable for the RTL8722DM, but not all functionality could be converted.