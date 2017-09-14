#include "fuzz/common-fuzz.h"

static unsigned int currently_fuzzing = 0;

bool is_fuzzing(void) {
    return currently_fuzzing;
}

int gen_fuzz(void* dest, size_t len) {
    int fd, readerr, result;

    if ((fd = open("/dev/random", O_RDONLY) < 0)) {
       printf("!!!! Cannot open random !!!!\n");
       result = -1;
    } else {
        if((readerr = read(fd, dest, len)) != len) {
            printf("!!!! read failed: %d !!!!\n", readerr);
            result = -1;
        }
        close(fd);
    }

    return result;
}

void register_fuzzer(unsigned int fuzzer_flag) {
    currently_fuzzing |= fuzzer_flag;
}

void unregister_fuzzer(unsigned int fuzzer_flag) {
    currently_fuzzing &= ~fuzzer_flag;
}
