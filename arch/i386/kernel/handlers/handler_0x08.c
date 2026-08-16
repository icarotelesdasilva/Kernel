#include <stdint.h>

extern void kernel_panic(const char *str);

void handler_0x08(const char* msg) {

kernel_panic(msg);

}
