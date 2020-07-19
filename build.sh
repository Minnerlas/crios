#!/bin/sh

ARCH=i386
AS=i686-elf-as
PUTANJA=/home/nikola/src/i686-elf/bin/
ROOTDIR=$(pwd)
IME=CriOS

make cln
mkdir build
cd boot
make AS=$AS
cd $ROOTDIR
cd kernel
./make.sh
cd $ROOTDIR
./link.sh
