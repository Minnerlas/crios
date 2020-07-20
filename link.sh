#!/bin/sh

#PUTANJA=/home/nikola/src/i686-elf/bin/
#CC=i686-elf-gcc
#ARCH=i386
LFLAGS="-T arch/$ARCH/linker.ld -ffreestanding -O2 -nostdlib -lgcc"
IME=CriOS

$PUTANJA$CCBIN build/* -o $IME.bin $LFLAGS
