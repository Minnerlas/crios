#!/bin/sh

AS="$PUTANJA$ASBIN"
AS32="$PUTANJA32$ASBIN32"

echo
echo "boot/"

case $ARCH in
	"i386")
		echo "$AS arch/$ARCH/boot.s -o ../build/boot.o"
		$AS arch/$ARCH/boot.s -o ../build/boot.o
		;;

	"x86_64")
		echo "$AS32 arch/$ARCH/boot.s -o ../build/boot.o"
		$AS32 arch/$ARCH/boot.s -o ../build/boot.o
		;;

	*)
		echo "Nepodrzana arhitektura $ARCH"
		exit 1
		;;
esac
