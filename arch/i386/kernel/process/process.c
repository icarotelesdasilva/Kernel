#include "process_test.h"

void task_a_entry(void);
void task_b_entry(void);

task_t *current;
task_t *next;

task_t task_a;
task_t task_b;

uint8_t stack_a[1024];
uint8_t stack_b[1024];


void process(void)
{
    uint32_t *sp_a;
    uint32_t *sp_b;

    task_a.pid = 1;
    task_a.state = 1;

    task_b.pid = 2;
    task_b.state = 1;


    

    sp_a = (uint32_t *)(stack_a + sizeof(stack_a));

    *(--sp_a) = 0x202;                  
    *(--sp_a) = 0x08;                   
    *(--sp_a) = (uint32_t)task_a_entry; 

    *(--sp_a) = 0; // EDI
    *(--sp_a) = 0; // ESI
    *(--sp_a) = 0; // EBP
    *(--sp_a) = 0; // ESP
    *(--sp_a) = 0; // EBX
    *(--sp_a) = 0; // EDX
    *(--sp_a) = 0; // ECX
    *(--sp_a) = 0; // EAX

    *(--sp_a) = 0x10; // DS
    *(--sp_a) = 0x10; // ES

    task_a.esp = (uintptr_t)sp_a;



    sp_b = (uint32_t *)(stack_b + sizeof(stack_b));

    *(--sp_b) = 0x202;                  
    *(--sp_b) = 0x08;                  
    *(--sp_b) = (uint32_t)task_b_entry; 

    *(--sp_b) = 0; // EDI
    *(--sp_b) = 0; // ESI
    *(--sp_b) = 0; // EBP
    *(--sp_b) = 0; // ESP
    *(--sp_b) = 0; // EBX
    *(--sp_b) = 0; // EDX
    *(--sp_b) = 0; // ECX
    *(--sp_b) = 0; // EAX

    *(--sp_b) = 0x10; // DS
    *(--sp_b) = 0x10; // ES

    task_b.esp = (uintptr_t)sp_b;


    current = &task_a;
    next = &task_b;
}


void task_a_entry(void)
{
    for (;;)
    {
    }
}


void task_b_entry(void)
{
    for (;;)
    {
    }
}