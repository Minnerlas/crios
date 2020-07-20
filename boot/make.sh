#!/bin/sh

AS="$PUTANJA$ASBIN"

case $ARCH in
	"i386")
		$AS arch/$ARCH/boot.s -o ../build/boot.o
		;;

	"x86_64")
		echo "test x64"
		;;

	*)
		echo "Nepodrzana arhitektura $ARCH"
		;;
esac
