#ifndef FUZZ_COMMON_H
#define FUZZ_COMMON_H

#define USB_FUZZ_FLAG   1

#include "qemu/osdep.h"

bool        is_fuzzing(void);
int         gen_fuzz(void*, size_t);
void        register_fuzzer(unsigned int);
void        unregister_fuzzer(unsigned int);

#endif
