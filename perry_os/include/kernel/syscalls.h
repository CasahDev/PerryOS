#if !defined(_KERNEL_SYSCALLS_H)
#define _KERNEL_SYSCALLS_H

void sys_exit(struct registers_t *regs);

void sys_open(struct registers_t *regs);

void sys_close(struct registers_t *regs);

#endif // _KERNEL_SYSCALLS_H
