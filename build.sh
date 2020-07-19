#!/bin/sh

ARCH=i386
AS=i686-elf-as
PUTANJA=/home/nikola/src/i686-elf/bin/
ROOTDIR=$(pwd)

make clean
mkdir build
cd boot
make AS=$AS
