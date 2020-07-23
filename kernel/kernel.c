#include <stdint.h>
#include <include/tty.h>

void kernel_main() {

	/* Initialize terminal interface */
	terminal_initialize();

	for(int i = 0; i<28; i++) {
		kprintf("%d\n Hello, kernel World! test \ntest test%d\n", i, i);
	}

	terminal_writestring("Ovo je test\n");
	kprintf("TEST %d\n", 42);
	kprintf("TEST %p\n", "test");

	asm("hlt;");

	//for(;;);

	for(int i = 0;; i++)
		kprintf("%d\n", i);
}
