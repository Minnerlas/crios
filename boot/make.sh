#!/bin/sh

echo
echo "boot/"
echo

$CC -fno-builtin -O2 -nostdinc -nostdlib -ffreestanding -g -Wall -Wextra -Werror -I. -MMD -mno-red-zone -mcmodel=kernel -fno-pie -Wa,--divide -c -o $ROOTDIR/build/boot.o boot.S
