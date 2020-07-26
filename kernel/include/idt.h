#include <stdint.h>
#include <include/isr.h>
#include <include/kernel.h>

#ifndef IDT_H
#define IDT_H

#define NIDT 256

struct IDTDescr {
	uint16_t offset_1; // offset bits 0..15
	uint16_t selector; // a code segment selector in GDT or LDT
	uint8_t ist;       // bits 0..2 holds Interrupt Stack Table offset, rest of bits zero.
	uint8_t type_attr; // type and attributes
	uint16_t offset_2; // offset bits 16..31
	uint32_t offset_3; // offset bits 32..63
	uint32_t zero;     // reserved
};


extern struct IDTDescr _idt[NIDT];
extern void *idtDescriptor;
extern void *_loadIDT();

/*
void PIC_remap(int offset1, int offset2) {
	unsigned char a1, a2;

	a1 = inb(PIC1_DATA);                        // save masks
	a2 = inb(PIC2_DATA);

	outb(PIC1_COMMAND, ICW1_INIT | ICW1_ICW4);  // starts the initialization sequence (in cascade mode)
	io_wait();
	outb(PIC2_COMMAND, ICW1_INIT | ICW1_ICW4);
	io_wait();
	outb(PIC1_DATA, offset1);                 // ICW2: Master PIC vector offset
	io_wait();
	outb(PIC2_DATA, offset2);                 // ICW2: Slave PIC vector offset
	io_wait();
	outb(PIC1_DATA, 4);                       // ICW3: tell Master PIC that there is a slave PIC at IRQ2 (0000 0100)
	io_wait();
	outb(PIC2_DATA, 2);                       // ICW3: tell Slave PIC its cascade identity (0000 0010)
	io_wait();

	outb(PIC1_DATA, ICW4_8086);
	io_wait();
	outb(PIC2_DATA, ICW4_8086);
	io_wait();

	outb(PIC1_DATA, a1);   // restore saved masks.
	outb(PIC2_DATA, a2);
}
*/


void remap_PIC(uint8_t off1, uint8_t off2) {
//void remap_PIC() {
	uint8_t a1, a2;
	a1 = inb(PIC1_DATA);
	a2 = inb(PIC2_DATA);

	outb(PIC1_COMMAND, ICW1_INIT | ICW1_ICW4);
	io_wait();
	outb(PIC2_COMMAND, ICW1_INIT | ICW1_ICW4);
	io_wait();
	outb(PIC1_DATA, off1);
	io_wait();
	outb(PIC2_DATA, off2);
	io_wait();
	//int a = 15;
	//outb(PIC1_DATA, a);
	//io_wait();
	//outb(PIC2_DATA, a+8);
	//io_wait();
	outb(PIC1_DATA, 4);
	io_wait();
	outb(PIC2_DATA, 2);
	io_wait();
	outb(PIC1_DATA, ICW4_8086);
	io_wait();
	outb(PIC2_DATA, ICW4_8086);
	io_wait();

	outb(PIC1_DATA, a1);
	io_wait();
	outb(PIC2_DATA, a2);
}


void setIDTentry(int i, void *irq_addr) {
	//kprintf("irqaddr %p\n", irq_addr);
	_idt[i].zero = 0;
	_idt[i].offset_1 = (uint16_t)(((uint64_t)irq_addr & 0xffff));
	_idt[i].offset_2 = (uint16_t)(((uint64_t)irq_addr & 0xffff0000) >> 16);
	_idt[i].offset_3 = (uint32_t)(((uint64_t)irq_addr) >> 32);
	_idt[i].ist = 0;
	_idt[i].selector = 0x08;
	_idt[i].type_attr = 0x8e;
}

void loadIDT() {
	for(int i = 0; i < 255; i++)
		setIDTentry(i, &irq_kbd);
		//setIDTentry(i, &irq_timer);

	//kprintf("%d\n", sizeof(struct IDTDescr));
	//setIDTentry(PIC1_OFFSET, &irq_timer);
	//setIDTentry(PIC1_OFFSET+1, &irq_kbd);
	//setIDTentry(0x21, &irq_kbd);
	//setIDTentry(9, &irq_kbd);
	//int a = 15;
	//setIDTentry(a, &irq_timer);
	//setIDTentry(a+1, &irq_kbd);
	//setIDTentry(8, &irq_double_fault);

	//PIC_remap(PIC1_OFFSET, PIC2_OFFSET);
	//outb(0x20, 0x11);
	//outb(0xA0, 0x11);
	//outb(0x21, 0x20);
	//outb(0xA1, 0x28);
	//outb(0x21, 0x04);
	//outb(0xA1, 0x02);
	//outb(0x21, 0x01);
	//outb(0xA1, 0x01);
	//outb(0x21, 0x0);
	//outb(0xA1, 0x0);

	int a = 15;
	remap_PIC(a, a+8);
	//remap_PIC();
	//remap_PIC(PIC1_OFFSET, PIC2_OFFSET);
	//MASKA 1 ZNAČI DA NIJE UKLJUČEN 
	//0x11111111 0xff NIŠTA
	//0x11111110 0xfe TAJMER
	//0x11111101 0xfd TASTATURA
	//0x11111100 0xfc TASTATURA I TAJMER
	outb(PIC1_DATA, 0xfd);
	outb(PIC2_DATA, 0xff);

	_loadIDT();
}

#endif /* IDT_H */
