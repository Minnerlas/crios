.global irq0
.type irq0, @function
irq0:
	cli
	push %rax
	push %rcx
	push %rdx
	push %rbx
	push %rbp
	push %rsi
	push %rdi
	
	call irq0_handler

	pop %rdi    
	pop %rsi    
	pop %rbp    
	pop %rbx    
	pop %rdx    
	pop %rcx
	pop %rax
	sti	
	
	iretq

.global irq_timer
.type irq_timer, @function
irq_timer:
	cli
	push %rax
	push %rcx
	push %rdx
	push %rbx
	push %rbp
	push %rsi
	push %rdi
	
	call irq_timer_handler
	
	pop %rdi    
	pop %rsi    
	pop %rbp    
	pop %rbx    
	pop %rdx    
	pop %rcx
	pop %rax
	
	sti
	iretq

.global irq_kbd
.type irq_kbd, @function
irq_kbd:
	cli
	push %rax
	push %rcx
	push %rdx
	push %rbx
	push %rbp
	push %rsi
	push %rdi
	
	call irq_kbd_handler
	
	pop %rdi    
	pop %rsi    
	pop %rbp    
	pop %rbx    
	pop %rdx    
	pop %rcx
	pop %rax
	sti
	
	iretq

.global irq_double_fault
.type irq_double_fault, @function
irq_double_fault:
	cli
	push %rax
	push %rcx
	push %rdx
	push %rbx
	push %rbp
	push %rsi
	push %rdi
	
	call irq_double_fault_handler
	
	pop %rdi    
	pop %rsi    
	pop %rbp    
	pop %rbx    
	pop %rdx    
	pop %rcx
	pop %rax
	sti
	
	iretq

.global irq_page_fault
.type irq_page_fault, @function
irq_page_fault:
	cli
	push %rax
	push %rcx
	push %rdx
	push %rbx
	push %rbp
	push %rsi
	push %rdi
	
	call irq_page_fault_handler
	
	pop %rdi    
	pop %rsi    
	pop %rbp    
	pop %rbx    
	pop %rdx    
	pop %rcx
	pop %rax
	sti
	
	iretq

.global irq_general_protection
.type irq_general_protection, @function
irq_general_protection:
	cli
	push %rax
	push %rcx
	push %rdx
	push %rbx
	push %rbp
	push %rsi
	push %rdi
	
	call irq_general_protection_handler
	
	pop %rdi    
	pop %rsi    
	pop %rbp    
	pop %rbx    
	pop %rdx    
	pop %rcx
	pop %rax
	sti
	
	iretq
