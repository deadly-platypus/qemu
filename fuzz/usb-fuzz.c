#include "fuzz/usb-fuzz.h"

static bool usb_fuzz = FALSE;

bool usb_fuzzing(void) {
    return usb_fuzz;
}

void start_usb_fuzz(void) {
    usb_fuzz = TRUE;
    register_fuzzer(USB_FUZZ_FLAG);
}

void stop_usb_fuzz(void) {
    usb_fuzz = FALSE;
    unregister_fuzzer(USB_FUZZ_FLAG);
}
