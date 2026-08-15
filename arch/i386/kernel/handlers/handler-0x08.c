#include <stdint.h>
extern void kernel_panic(const char *str)

void double_fault {

kernel_panic("I received a Double fault");

}