extern void irq0();
extern void irq_timer();
extern void irq_kbd();
extern void irq_double_fault();
extern void irq_general_protection();

void irq0_handler();
void irq_timer_handler();
void irq_kbd_handler();
void irq_double_fault_handler();
void irq_general_protection_handler();
