#!/bin/sh

export ARCH=i386
# export ARCH=x86_64

case $ARCH in
	"i386")
		export ASBIN=i686-elf-as
		export CCBIN=i686-elf-gcc
		export PUTANJA=/home/nikola/i686-gcc/bin/
		;;
	"x86_64")
		export ASBIN=x86_64-elf-as
		export ASBIN32=i686-elf-as
		export CCBIN=x86_64-elf-gcc
		export CCBIN32=i686-elf-gcc
		export PUTANJA32=/home/nikola/i686-gcc/bin/
		export PUTANJA=/home/nikola/x86_64-gcc/bin/
		;;
esac

ROOTDIR=$(pwd)
IME=CriOS

make cln
mkdir build
cd boot
#make AS=$AS PUTANJA=$PUTANJA
./make.sh
cd $ROOTDIR
cd kernel
./make.sh
cd $ROOTDIR
./link.sh
