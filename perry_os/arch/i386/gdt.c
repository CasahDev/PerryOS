#include <kernel/gdt.h>

#define ENTRY_NUMBER 5

struct gdt_entry_t gdt_entries[ENTRY_NUMBER];
struct gdt_ptr_t   gdt_ptr;

void init_gdt() {
    gdt_ptr.limit = (sizeof(struct gdt_entry_t) * ENTRY_NUMBER) - 1;
    gdt_ptr.base  = (uint32_t)&gdt_entries;

    // 0: NULL Descriptor
    gdt_set_gate(0, 0, 0, 0, 0);

    // 1: Kernel Code Segment (Offset 0x08)
    // Base: 0, Limite: 4GB, Access: 0x9A, Flags: 0xC (4KB blocks, 32-bit)
    // Note: 0xCF = Flags 0xC0 + Limit High 0x0F
    gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);

    // 2: Kernel Data Segment (Offset 0x10)
    // Base: 0, Limite: 4GB, Access: 0x92, Flags: 0xC
    gdt_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF);

    // 3: User Code Segment (Offset 0x18) -> Pour plus tard
    gdt_set_gate(3, 0, 0xFFFFFFFF, 0xFA, 0xCF); 

    // 4: User Data Segment (Offset 0x20) -> Pour plus tard
    gdt_set_gate(4, 0, 0xFFFFFFFF, 0xF2, 0xCF);

    gdt_flush((uint32_t)&gdt_ptr);
}

void gdt_set_gate(int32_t num, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran) {
    gdt_entries[num].base_low    = (base & 0xFFFF);
    gdt_entries[num].base_middle = (base >> 16) & 0xFF;
    gdt_entries[num].base_high   = (base >> 24) & 0xFF;

    gdt_entries[num].limit_low   = (limit & 0xFFFF);
    gdt_entries[num].granularity = (limit >> 16) & 0x0F;

    gdt_entries[num].granularity |= gran & 0xF0;
    gdt_entries[num].access      = access;
}