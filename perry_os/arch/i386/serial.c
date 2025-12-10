#include <kernel/serial.h>
#include <string.h>

#define COMM_PORT 0x3F8

void outb(const uint16_t port, const uint8_t val) {
    asm volatile ("outb %0, %1" : : "a"(val), "Nd"(port));
}

void init_serial() {
    // Disable port interuptions
    outb(COMM_PORT + 1, 0x00);

    // Enable DLAB (Divisor Latch Access Bit)
    outb(COMM_PORT + 3, 0x80);

    // DLAB speed (in bauds): 115200 / 0x00 0x01 = 115200 bauds
    outb(COMM_PORT, 0x01);
    outb(COMM_PORT + 1, 0x00);

    // Configure 8N1 format
    outb(COMM_PORT + 3, 0x03);

    // Configure buffers
    outb(COMM_PORT + 2, 0xC7);

    // Configure RTS (Request to send) and DTS (Data terminal Ready)
    outb(COMM_PORT + 4, 0x0B);
}

int is_transmit_empty() {
   return inb(PORT + 5) & 0x20;
}

void serial_putc(const char c) {
    while (is_transmit_empty() == 0); // polling
    outb(COMM_PORT, c);
}

void serial_putstring(const char* str) {
    for (int i = 0; i < strlen(str); i++) {
        serial_putc(str[i]);
    }
}