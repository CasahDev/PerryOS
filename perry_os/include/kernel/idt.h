#ifndef _KERNEL_IDT_H
#define _KERNEL_IDT_H

#include <stdint.h>

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

/**
 * @param ptr Represents the table to load
 */
static inline void idt_load(void* ptr);

/**
 * @param num Interuption number
 * @param base Function address (ex: (uint32_t)&isr_wrapper)
 * @param selector Segment selector (ex: 0x08)
 * @param flags Flags and attributes (ex: 0x8E)
 */
void idt_set_gate(uint8_t num, uint32_t base, uint16_t selector, uint8_t flags);


#endif