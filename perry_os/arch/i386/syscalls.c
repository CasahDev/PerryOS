#include <kernel/syscalls.h>
#include <kernel/serial.h>
#include <string.h>

void sys_exit(struct registers_t *regs) {
    char buffer[16];
    serial_putstring("[SYSCALL] exit called with status: ");
    inttostr(regs->ebx, buffer);
    serial_putstring(buffer);
    serial_putstring("\n");

    // TODO: stop the proc
}

void sys_open(struct registers_t *regs) {
    serial_putstring("[SYSCALL] open called for file: ");
    
    const char* filename = (const char*) regs->ebx;
    serial_putstring(filename);

    char flags[16];
    inttostr(regs->ecx, flags);
    serial_putstring(" | flags: ");
    serial_putstring(flags);
    serial_putstring("\n");

    // TODO give access to the file
}

void sys_close(struct registers_t *regs) {

}
