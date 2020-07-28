IME=CriOS

cln:
	rm -rvf build

clean:
	rm -rvf build
	rm -rvf iso
	rm -vf ${IME}* 
	rm -vf *.iso
	rm -vf *.dmp
	rm -vf *.sym

iso: kernel
	mkdir -p iso/boot/grub
	cp grub.cfg iso/boot/grub/
	cp ${IME}*.bin iso/boot/${IME}.bin
	grub-mkrescue -o ${IME}.iso iso

run: runiso

runcurses:
	qemu-system-x86_64 -curses -cdrom *.iso

runiso:
	qemu-system-x86_64 -cdrom *.iso

dbg:
	objcopy --only-keep-debug ${IME}.bin kernel.sym
	objcopy --strip-debug ${IME}.bin
	qemu-system-x86_64 -s -S -cdrom *.iso 

dbgcurses:
	objcopy --only-keep-debug ${IME}.bin kernel.sym
	objcopy --strip-debug ${IME}.bin
	qemu-system-x86_64 -curses -s -S -cdrom *.iso 
