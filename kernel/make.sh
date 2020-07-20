#!/bin/sh
#ARCH=i386
#PUTANJA=/home/nikola/src/i686-elf/bin/
#CCBIN=i686-elf-gcc
CC="$PUTANJA$CCBIN"
CFLAGS="-std=gnu99 -ffreestanding -O2 -Wall -Wextra -mno-red-zone"

echo 
echo "kernel/"

case $ARCH in 
	"i386")
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
		;;

	"x86_64")
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
		echo "Ovo je test $ARCH"
		;;
	*)
		echo "TEST $ARCH"
		;;
esac

