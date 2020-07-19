PUTANJA = /home/nikola/src/i686-elf/bin/

all: kernel.c
	${PUTANJA}i686-elf-gcc -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	${PUTANJA}i686-elf-gcc -T linker.ld -o myos.bin -ffreestanding -O2 -nostdlib boot.o kernel.o -lgcc

test: all
	qemu-system-i386 -kernel myos.bin

run:
	qemu-system-i386 -kernel myos.bin

clean:
	rm -rvf build

tt:
	echo ${PUTANJA}
