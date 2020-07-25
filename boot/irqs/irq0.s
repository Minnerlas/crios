.global irq0
.type irq0, @function
irq0:
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
	
	iretq
