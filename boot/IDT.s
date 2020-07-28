.section .data
.global idtDescriptor
idtDescriptor:
	.2byte 255
	.8byte _idt

.global _loadIDT
.type _loadIDT, @function
_loadIDT:
	lidt (idtDescriptor)
	ret
