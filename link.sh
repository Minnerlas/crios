#!/bin/sh

#PUTANJA=/home/nikola/src/i686-elf/bin/
#CC=i686-elf-gcc
#ARCH=i386
LFLAGS="-T arch/$ARCH/linker.ld -ffreestanding -O2 -nostdlib -lgcc"
IME=CriOS

case $ARCH in
	"i386")
		$PUTANJA$CCBIN build/* -o "$IME$ARCH.bin" $LFLAGS
		;;

	"x86_64")
		$PUTANJA$CCBIN build/* -o "$IME$ARCH.bin" $LFLAGS
		;;

	*)
		echo "Nepodrzana arhitektura"
		exit 1
		;;
esac

