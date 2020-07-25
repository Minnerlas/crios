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

inline void io_wait() {
    /* Port 0x80 is used for 'checkpoints' during POST. */
    /* The Linux kernel seems to think it is free for use :-/ */
    asm volatile ( "outb %%al, $0x80" : : "a"(0) );
    /* %%al instead of %0 makes no difference.  TODO: does the register need to be zeroed? */
}
