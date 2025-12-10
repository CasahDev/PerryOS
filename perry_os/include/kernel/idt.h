#ifndef _KERNEL_IDT_H
#define _KERNEL_IDT_H

#include <stdint.h>

#define NUMBER_OF_SYSCALLS 10

typedef void (*syscall_t)(struct registers_t *);

// Represents an entry for the IDT table
struct idt_entry_t {
   uint16_t offset_low;   // Offset bits 0..15
   uint16_t selector;     // Selector
   uint8_t zero;         // Reserved / Zero
   uint8_t type_attr;    // Type & Attributes
   uint16_t offset_high;  // Offset bits 16..31
} __attribute__((packed));

// Represents the IDTR (IDT reference)
struct idt_ptr_t
{
    uint16_t limit;
    uint32_t base;
} __attribute__((packed));

// Represents a register
struct registers_t {
    uint32_t edi;// 5th arg
    uint32_t esi;// 4th arg
    uint32_t ebp;
    uint32_t esp;
    uint32_t ebx; // 1st arg
    uint32_t edx; // 3rd arg
    uint32_t ecx; // 2nd arg
    uint32_t eax; // Service code
} __attribute__((packed));

void init_idt();

void init_syscall_table();


/**
 * @param num Interuption number
 * @param base Function address (ex: (uint32_t)&isr_wrapper)
 * @param selector Segment selector (ex: 0x08)
 * @param flags Flags and attributes (ex: 0x8E)
 */
void idt_set_gate(uint8_t num, uint32_t base, uint16_t selector, uint8_t flags);

extern void _isr_wrapper(void);

void isr_handler(struct registers_t *regs);

#endif