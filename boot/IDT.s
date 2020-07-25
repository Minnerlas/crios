.section .data
.global idtDescriptor
idtDescriptor:
	.short 0x100
	.8byte _idt

.global _loadIDT
.type _loadIDT, @function
_loadIDT:
	lidt (idtDescriptor)
	ret
