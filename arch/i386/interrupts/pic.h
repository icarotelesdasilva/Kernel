#ifndef PIC_H
#define PIC_H
#define master_pic_command 0x20
#define master_pic_data 0x21
#define slave_pic_command 0xA0
#define slave_pic_data 0xA1
#define PIC_ICW1_INIT 0x11
#define MASTER_VECTOR_BASE 0x20
#define SLAVE_VECTOR_BASE  0x28
#include <stdint.h>

void pic_remap(uint8_t offset1,uint8_t offset2); 



#endif
