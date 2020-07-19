PUTANJA = /home/nikola/src/i686-elf/bin/
CC = i686-elf-gcc
LFLAGS = -T linker.ld -ffreestanding -O2 -nostdlib -lgcc
IME = CriOS

all: kernel.c
	${PUTANJA}i686-elf-gcc -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	${PUTANJA}i686-elf-gcc -T linker.ld -o myos.bin -ffreestanding -O2 -nostdlib boot.o kernel.o -lgcc

run:
	qemu-system-i386 -kernel ${IME}.bin

clean:
	rm -rvf build
	rm -f *.bin

link:
	${PUTANJA}${CC} -o myos.bin  build/*

cln:
	rm -rvf build
