#include <kernel/idt.h>
#include <string.h>
#include <kernel/syscalls.h>
#include <kernel/serial.h>

struct idt_entry_t idt_table[256];

struct idt_ptr_t idt_ptr = {
    sizeof(idt_table) - 1,
    (uint32_t) idt_table
};

syscall_t syscalls[NUMBER_OF_SYSCALLS];

void init_idt() {
    asm volatile ("lidt %0" : : "m"(idt_ptr));

    idt_set_gate(0x20, (uint32_t) _isr_wrapper, 0x08, 0x8E);
}

void init_syscall_table() {
    syscalls[1] = sys_exit;
    syscalls[2] = sys_open;
    syscalls[3] = sys_close;
}

void idt_set_gate(uint8_t num, uint32_t base, uint16_t selector, uint8_t flags) {
    idt_table[num].selector = selector;
    idt_table[num].zero = 0;
    idt_table[num].type_attr = flags;
    idt_table[num].offset_low = base & 0xFFFF;
    idt_table[num].offset_high = (base >> 16) & 0xFFFF;
}

void isr_handler(struct registers_t *regs) {

    if (sizeof(syscalls) / sizeof(syscall_t) > regs->eax && syscalls[regs->eax] != NULL) {
        syscalls[regs->eax](regs);
    } else {
        // Optionnel : Afficher un message d'erreur de debug
        serial_putstring("Erreur: Appel systeme inconnu !\n");
    }
}


