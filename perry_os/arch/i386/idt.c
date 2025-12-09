#include <kernel/idt.h>
#include <string.h>
#include <kernel/tty.h>

struct idt_entry_t idt_table[256];

struct idt_ptr_t idt_ptr = {
    sizeof(idt_table) - 1,
    (uint32_t) idt_table
};

void init_idt() {
    asm volatile ("lidt %0" : : "m"(idt_ptr));

    idt_set_gate(0x20, (uint32_t) _isr_wrapper, 0x08, 0x8E);

    
    asm volatile ("int $32");
}

void idt_set_gate(uint8_t num, uint32_t base, uint16_t selector, uint8_t flags) {
    idt_table[num].selector = selector;
    idt_table[num].zero = 0;
    idt_table[num].type_attr = flags;
    idt_table[num].offset_low = base & 0xFFFF;
    idt_table[num].offset_high = (base >> 16) & 0xFFFF;
}

void isr_handler(struct registers_t *regs) {
    char eax[16];

    // Affichage de EAX
    terminal_writestring("Interruption reçue !\n");
    terminal_writestring("EAX = ");
    inttostr(regs->eax, eax);
    terminal_writestring(eax);
    terminal_writestring("\n");

    char ebx[16];
    // Affichage de EBX
    terminal_writestring("EBX = ");
    inttostr(regs->ebx, ebx);
    terminal_writestring(ebx);
    terminal_writestring("\n");
}
