#include <stdint.h>
#include <sys/types.h>

extern void serial_print(const char *str);
typedef struct {

	uint32_t gs;
	uint32_t fs;
	uint32_t es;
	uint32_t ds;


	uint32_t edi;
	uint32_t esi;
	uint32_t ebp;
	uint32_t esp_placeholder;
	uint32_t ebx;
	uint32_t edx;
	uint32_t ecx;
	uint32_t eax;


}registers_t;
void handler_syscall(registers_t *regs) {
    switch (regs->eax) {
        case 1:
            serial_print("syslog: 1\n");
            regs->eax = 0; 
            break;
        default:
            serial_print("syslog: syscall erorr\n");
            regs->eax = (uint32_t)-1; 
            break;
    }
}