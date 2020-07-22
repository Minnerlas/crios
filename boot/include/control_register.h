#ifndef _ARCH_X86_64_CONTROL_REGISTER_H_
#define _ARCH_X86_64_CONTROL_REGISTER_H_

#define CONTROL_REGISTER0_PROTECTED_MODE_ENABLED (1 << 0)
#define CONTROL_REGISTER0_EXTENSION_TYPE (1 << 4)
#define CONTROL_REGISTER0_PAGE (1 << 31)

#define CONTROL_REGISTER4_PAGE_SIZE_EXTENSION (1 << 4)
#define CONTROL_REGISTER4_PHYSICAL_ADDRESS_EXTENSION (1 << 5)

#endif // _ARCH_X86_64_CONTROL_REGISTER_H_
