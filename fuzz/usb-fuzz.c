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

static uint64_t fuzz_dumb_rand64(void) {
    return (((uint64_t)rand() << 32) | rand());
}

uint64_t fuzz_rand64(void) {
    int fd, readerr;
    uint64_t result;

    if ((fd = open("/dev/random", O_RDONLY) < 0)) {
       printf("!!!! Cannot open random !!!!\n");
       result = fuzz_dumb_rand64();
    } else {
        if((readerr = read(fd, &result, sizeof(uint64_t))) != sizeof(uint64_t)) {
            printf("!!!! read failed: %d !!!!\n", readerr);
            result = fuzz_dumb_rand64();
        }
        close(fd);
    }

    return result;
}
