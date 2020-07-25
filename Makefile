IME=CriOS

cln:
	rm -rvf build

clean:
	rm -rvf build
	rm -rvf iso
	rm -vf ${IME}* 
	rm -vf *.iso
	rm -vf *.dmp

iso: kernel
	mkdir -p iso/boot/grub
	cp grub.cfg iso/boot/grub/
	cp ${IME}*.bin iso/boot/${IME}.bin
	grub-mkrescue -o ${IME}.iso iso

run: runiso

runiso:
	qemu-system-x86_64 -cdrom *.iso
