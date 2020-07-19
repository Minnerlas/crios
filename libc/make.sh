#!/bin/sh
ARCH=i386
PUTANJA=/home/nikola/src/i686-elf/bin/
CCBIN=i686-elf-gcc
CC="$PUTANJA$CCBIN"
CFLAGS="-std=gnu99 -ffreestanding -O2 -Wall -Wextra"

for f in arch/$ARCH/*.c
do
	t=${f%.c}.o
	t=${t##*/}
	# echo $CC -c $f -o ../build/$t $CFLAGS
	$CC -c $f -o ../build/$t $CFLAGS
done

pwd

for dir in ./*/
do
	for f in $dir*.c
	do
		echo $f
		t=${f%.c}.o
		t=${t##*/}
		# echo $CC -c $f -o ../build/$t $CFLAGS
		$CC -c $f -o ../build/$t $CFLAGS
	done
done
