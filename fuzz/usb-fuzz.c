#include "fuzz/usb-fuzz.h"

static bool usb_fuzz = FALSE;

bool is_fuzzing(void) {
    return usb_fuzzing();
}

bool usb_fuzzing(void) {
    return usb_fuzz;
}

void start_usb_fuzz(void) {
    usb_fuzz = TRUE;
}

void stop_usb_fuzz(void) {
    usb_fuzz = FALSE;
}
