#!/bin/sh

echo
echo "kernel/"
echo

for d in */
do
	echo $d
	for f in $d*.c
	do
		t=${f%.c}.o
		t=${t##*/}
		echo $CC -c $f -o $ROOTDIR/build/$t $CFLAGS
		$CC -c $f -o $ROOTDIR/build/$t $CFLAGS
	done
done

#$CC -c kernel.c -o ../build/kernel.o $CFLAGS

for f in *.c
do
	t=${f%.c}.o
	t=${t##*/}
	echo $CC -c $f -o $ROOTDIR/build/$t $CFLAGS
	$CC -c $f -o $ROOTDIR/build/$t $CFLAGS
done
