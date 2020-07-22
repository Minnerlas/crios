// #include "kernel.h"
#include "include/tty.h"
// #include "multiboot.h"

/* Check if the compiler thinks you are targeting the wrong operating system. */
// #if defined(__linux__)
// #error "You are not using a cross-compiler, you will most certainly run into trouble"
// #endif

// extern int size;

void kernel_main() {
	/* Initialize terminal interface */
	terminal_initialize();

	/* Newline support is left as an exercise. */
	//for(int i = 0; i<28; i++) {
	//	terminal_putchar(i/10+'0');
	//	terminal_putchar(i%10+'0');
	//	terminal_putchar('\n');
	//	terminal_writestring(" Hello, kernel World! test \ntest test\n");
	//}
	//
	for(int i = 0; i<28; i++) {
		kprintf("%d\n Hello, kernel World! test \ntest test%d\n", i, i);
	}

	terminal_writestring("Ovo je test\n");
	kprintf("TEST %d\n", 42);
	kprintf("TEST %p\n", "test");

	for(int i = 0;; i++)
		kprintf("%d\n", i);

	// kprintf("\n%b flags\n",		test->flags);
	// kprintf("%p mem_lower\n",	test->mem_lower);
	// kprintf("%p mem_upper\n",	test->mem_upper);
	// kprintf("%p boot_device\n",	test->boot_device);
	// kprintf("%s cmdline\n",		test->cmdline);
	// kprintf("%b mods_count\n",	test->mods_count);
	// kprintf("%b mods_addr\n",	test->mods_addr);
	// kprintf("%s boot_lader_name\n",	test->boot_loader_name);
}
