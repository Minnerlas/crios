#!/bin/sh
#ARCH=i386
#PUTANJA=/home/nikola/src/i686-elf/bin/
#CCBIN=i686-elf-gcc
CC="$PUTANJA$CCBIN"
CFLAGS="-std=gnu99 -ffreestanding -O2 -Wall -Wextra -mno-red-zone"

for f in arch/$ARCH/*.c
do
	t=${f%.c}.o
	t=${t##*/}
	echo $CC -c $f -o ../build/$t $CFLAGS
	$CC -c $f -o ../build/$t $CFLAGS
done

#$CC -c kernel.c -o ../build/kernel.o $CFLAGS

for f in *.c
do
	t=${f%.c}.o
	t=${t##*/}
	echo $CC -c $f -o ../build/$t $CFLAGS
	$CC -c $f -o ../build/$t $CFLAGS
done

