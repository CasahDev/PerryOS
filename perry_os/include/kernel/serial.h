#ifndef _KERNEL_SERIAL_H
#define _KERNEL_SERIAL_H

#include <stdint.h>

void outb(const uint16_t port, const uint8_t val);
void init_serial();
void serial_putc(const char c);
void serial_putstring(const char* str); 

#endif
