#ifndef USB_FUZZ_H
#define USB_FUZZ_H
#include "fuzz/common-fuzz.h"

void start_usb_fuzz(void);
void stop_usb_fuzz(void);

bool usb_fuzzing(void);

#endif /* USB_FUZZ_H */
