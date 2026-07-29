#include "pmm.h"
#include "../boot/multiboot.h"
#include <stdint.h>
extern void kernel_panic(char *str);
#define MAX_MEM_BYTES (128 * 1024 * 1024) 
#define TOTAL_BLOCKS (MAX_MEM_BYTES / PAGE_SIZE)

static uint32_t pmm_bitmap[TOTAL_BLOCKS / 32]; 
static void set_bit(uint32_t bit) {
    pmm_bitmap[bit / 32] |= (1 << (bit % 32));
}

static void clear_bit(uint32_t bit) {
    pmm_bitmap[bit / 32] &= ~(1 << (bit % 32));
}
static int test_bit(uint32_t bit) {
    return (pmm_bitmap[bit / 32] & (1 << (bit % 32))) != 0;
}
void pmm_init(uintptr_t mb_addr) {
    for (uint32_t i = 0; i < TOTAL_BLOCKS / 32; i++) {
        pmm_bitmap[i] = 0xFFFFFFFF;
    }

    multiboot_info_t *mb = (multiboot_info_t *)mb_addr;
    if (!(mb->flags & MULTIBOOT_FLAG_MMAP)) kernel_panic("Kernel Panic! error for pmm.");

    return;

    multiboot_memory_map_t *mmap = (multiboot_memory_map_t *)mb->mmap_addr;
    uintptr_t mmap_end = mb->mmap_addr + mb->mmap_length;

    while ((uintptr_t)mmap < mmap_end) {
        if (mmap->type == MULTIBOOT_MEMORY_AVAILABLE) {
            uintptr_t start_block = (uintptr_t) mmap->addr / PAGE_SIZE;
            uintptr_t block_count = (uintptr_t)mmap->len / PAGE_SIZE;

            for (uint32_t i = 0; i < block_count; i++) {
                if ((start_block + i) < TOTAL_BLOCKS) {
                    clear_bit(start_block + i);
                }
            }
        }
        mmap = (multiboot_memory_map_t *)((uintptr_t)mmap + mmap->size + sizeof(mmap->size));
    }

    for (uint32_t b = 0; b < (1024 * 1024 / PAGE_SIZE); b++) {
        set_bit(b);
    }
}

void* pmm_alloc_block(void) {
    for (uintptr_t i = 0; i < TOTAL_BLOCKS; i++) {
        if (!test_bit(i)) {
            set_bit(i);
            return (void*)(i * PAGE_SIZE);
        }
    }
    return 0;
}

void pmm_free_block(void* ptr) {
    uintptr_t block = (uintptr_t)ptr / PAGE_SIZE;
    if (block < TOTAL_BLOCKS) {
        clear_bit(block);
    }
}
