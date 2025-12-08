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


#endif