#include <stdint.h>
#include <include/kernel.h>

void outb(uint16_t port, uint8_t val) {
	asm volatile("outb %0, %1\n": : "a"(val), "Nd"(port));
}

uint8_t inb(uint16_t port) {
	uint8_t ret;
	asm volatile("inb %1, %0\n" : "=a"(ret) : "Nd"(port));
	return ret;
}
