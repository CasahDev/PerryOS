#include <kernel/idt.h>

extern void isr_wrapper(void);

struct idt_entry_t idt_table[256];

struct idt_ptr_t idt_ptr = {
    sizeof(idt_table) - 1,
    (uint32_t) idt_table
};

static inline void idt_load(void* ptr) {
    asm volatile ("lidt %0" : : "m"(*((idt_ptr_t *) ptr)));
    isr_wrapper();
}

void idt_set_gate(uint8_t num, uint32_t base, uint16_t selector, uint8_t flags) {
    idt_table[num].selector = selector;
    idt_table[num].zero = 0;
    idt_table[num].type_attr = flags;
    idt_table[num].offset_low = base & 0xFFFF
    idt_table[num].offset_high = (base >> 16) & 0xFFFF;
}