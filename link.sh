#!/bin/sh

echo 
echo linkovanje

echo "$CC -z max-page-size=0x1000 -fno-builtin -O2 -nostdinc -nostdlib -ffreestanding -g -Wall -Wextra -Werror -I. -MMD -mno-red-zone -mcmodel=kernel -Wl,--build-id=none -T kernel.ld -o ../$IME.bin *.o"
$CC -z max-page-size=0x1000 -fno-builtin -O2 -nostdinc -nostdlib -ffreestanding -g -Wall -Wextra -Werror -I. -MMD -mno-red-zone -mcmodel=kernel -Wl,--build-id=none -T kernel.ld -o ../$IME.bin *.o

echo 
echo 
