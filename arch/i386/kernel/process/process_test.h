#ifndef PROCESS_TEST_H
#define PROCESS_TEST_H
#include <stdint.h>


/*
* NOTE: This is a test management file.
* which isn't doing anything for now.
* (This does not affect the behavior of the kernel and anything yet).
*/

typedef struct {
    uint32_t pid;
    uintptr_t esp; 
    uint32_t state;

}process;

#endif

