#!/bin/sh

export ARCH=i386
export AS=i686-elf-as
export CCBIN=i686-elf-gcc
export PUTANJA=/home/nikola/i686-gcc/bin/
ROOTDIR=$(pwd)
IME=CriOS

make cln
mkdir build
cd boot
make AS=$AS PUTANJA=$PUTANJA
cd $ROOTDIR
cd kernel
./make.sh
cd $ROOTDIR
./link.sh
