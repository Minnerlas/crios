ARCH = i386
PUTANJA = /home/nikola/src/i686-elf/bin/
CC = i686-elf-gcc
CFLAGS = -std=gnu99 -ffreestanding -O2 -Wall -Wextra
DEPS = arch/${ARCH}/tty.c tty.h

all: kernel.c arch/${ARCH}/tty.c tty.h
	${PUTANJA}${CC} -c kernel.c -o ../build/kernel.o ${CFLAGS}
	${PUTANJA}${CC} -c arch/${ARCH}/* -o ../build/ ${CFLAGS}
	echo ${PUTANJA}${CC} -T linker.ld -o myos.bin -ffreestanding -O2 -nostdlib boot.o kernel.o -lgcc

%.o: arch/${ARCH}/%.c
	echo $<
	${PUTANJA}${CC} -c -o ../build/$@ $< ${CFLAGS}

kernel: kernel.c ${DEPS}
	${PUTANJA}${CC} -c kernel.c -o ../build/kernel.o ${CFLAGS}

 
