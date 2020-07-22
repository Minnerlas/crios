#!/bin/sh

export ROOTDIR=$(pwd)
export CC="x86_64-elf-gcc"
export IME=CriOS
export CFLAGS="-std=gnu99 -fno-builtin -O2 -nostdlib -ffreestanding -g -Wall -Wextra -Werror -I. -MMD -mno-red-zone -mcmodel=kernel -fno-pie -c"

make cln
mkdir build

cd boot
./make.sh
cd $ROOTDIR/kernel
./make.sh
cd $ROOTDIR/libc
./make.sh
cd $ROOTDIR

cp kernel.ld build/
cp link.sh build/
cd build
./link.sh
cd $ROOTDIR

rm -rvf iso
make iso

echo
echo "Gotovo"
