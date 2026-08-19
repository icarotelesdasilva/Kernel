#include <stdint.h>
extern void irq12_stub(void);
extern void idt_set_gate(uint8_t num, uint32_t base, uint16_t sel, uint8_t flags);
#include "../interrupts/io.h"

#define PS2_DATA_PORT   0x60
#define PS2_STATUS_PORT 0x64
#define PS2_CMD_PORT    0x64

typedef struct {
    int32_t x;
    int32_t y;
    uint8_t left_button;
    uint8_t right_button;
    uint8_t middle_button;
} ps2_mouse_t;

static ps2_mouse_t g_mouse = {0, 0, 0, 0, 0};
static uint8_t mouse_cycle = 0;
static uint8_t mouse_packet[3];

static void mouse_wait(uint8_t type) {
    uint32_t timeout = 100000;
    if (type == 0) {
        while ((inb(PS2_STATUS_PORT) & 1) == 0 && --timeout);
    } else {
        while ((inb(PS2_STATUS_PORT) & 2) != 0 && --timeout);
    }
}

static void mouse_write(uint8_t data) {
    mouse_wait(1);
    outb(PS2_CMD_PORT, 0xD4); 
    mouse_wait(1);
    outb(PS2_DATA_PORT, data);
}

static uint8_t mouse_read(void) {
    mouse_wait(0);
    return inb(PS2_DATA_PORT);
}

void ps2_mouse_init(int screen_width, int screen_height) {
    uint8_t status;

    g_mouse.x = screen_width / 2;
    g_mouse.y = screen_height / 2;

    mouse_wait(1);
    outb(PS2_CMD_PORT, 0xA8);

    mouse_wait(1);
    outb(PS2_CMD_PORT, 0x20);
    status = mouse_read();

    status |= (1 << 1);
    status &= ~(1 << 5);

    mouse_wait(1);
    outb(PS2_CMD_PORT, 0x60);
    mouse_wait(1);
    outb(PS2_DATA_PORT, status);

    mouse_write(0xF4);
    mouse_read();
}

void ps2_mouse_handle_interrupt(int screen_width, int screen_height) {
    uint8_t status = inb(PS2_STATUS_PORT);
    
    if (!(status & 0x01) || !(status & 0x20)) {
        return;
    }

    uint8_t data = inb(PS2_DATA_PORT);

    if (mouse_cycle == 0) {
        if (data & 0x08) {
            mouse_packet[0] = data;
            mouse_cycle = 1;
        }
        return;
    }

    if (mouse_cycle == 1) {
        mouse_packet[1] = data;
        mouse_cycle = 2;
        return;
    }

    if (mouse_cycle == 2) {
        mouse_packet[2] = data;
        mouse_cycle = 0;

        g_mouse.left_button   = mouse_packet[0] & 0x01;
        g_mouse.right_button  = (mouse_packet[0] >> 1) & 0x01;
        g_mouse.middle_button = (mouse_packet[0] >> 2) & 0x01;

        int32_t delta_x = (int32_t)mouse_packet[1];
        int32_t delta_y = (int32_t)mouse_packet[2];

        if (mouse_packet[0] & 0x10) delta_x |= 0xFFFFFF00; 
        if (mouse_packet[0] & 0x20) delta_y |= 0xFFFFFF00; 

        g_mouse.x += delta_x;
        g_mouse.y -= delta_y; 

        if (g_mouse.x < 0) g_mouse.x = 0;
        if (g_mouse.y < 0) g_mouse.y = 0;
        if (g_mouse.x >= screen_width)  g_mouse.x = screen_width - 1;
        if (g_mouse.y >= screen_height) g_mouse.y = screen_height - 1;
    }
}

ps2_mouse_t ps2_mouse_get_state(void) {
    return g_mouse;
}

void unmask_mouse_irq(void) {

uint8_t master_mask = inb(0x21);
    outb(0x21, master_mask & ~(1 << 2));

uint8_t slave_mask = inb(0xA1);
    outb(0xA1, slave_mask & ~(1 << 4));
}
   
  
void mouse_register_interrupt(void) {
    idt_set_gate(44, (uint32_t)irq12_stub, 0x08, 0x8E);
}