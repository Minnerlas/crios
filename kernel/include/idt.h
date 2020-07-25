#include <stdint.h>
#include <include/isr.h>
#include <include/kernel.h>

#ifndef IDT_H
#define IDT_H

struct IDTDescr {
	uint16_t offset_1; // offset bits 0..15
	uint16_t selector; // a code segment selector in GDT or LDT
	uint8_t ist;       // bits 0..2 holds Interrupt Stack Table offset, rest of bits zero.
	uint8_t type_attr; // type and attributes
	uint16_t offset_2; // offset bits 16..31
	uint32_t offset_3; // offset bits 32..63
	uint32_t zero;     // reserved
};

#define NIDT 256

extern struct IDTDescr _idt[NIDT];
//struct IDTDescr _idt[NIDT];
extern void *idtDescriptor;
extern void *_loadIDT();

void loadIDT() {
	for(int i = 0; i < NIDT; i++) {
		_idt[i].zero = 0;
		_idt[i].offset_1 = (uint16_t)(((uint64_t)&irq0 & 0xffff));
		//_idt[i].offset_2 = (uint16_t)(((uint64_t)&irq0 & 0xffff0000) >> 16);
		//_idt[i].offset_3 = (uint32_t)(((uint64_t)&irq0 & 0xffffffff00000000) >> 32);
		_idt[i].offset_2 = (uint16_t)(((uint64_t)&irq0) >> 16);
		_idt[i].offset_3 = (uint32_t)(((uint64_t)&irq0) >> 32);
		_idt[i].ist = 0;
		_idt[i].selector = 0x08;
		_idt[i].type_attr = 0x8e;
	}

	outb(0x21, 0xfd);
	outb(0xa1, 0xff);

	_loadIDT();

	//asm("lidt (%0)"
	//		:
	//	   	: "r" (idtDescriptor) 
	//);
}

#endif /* IDT_H */
