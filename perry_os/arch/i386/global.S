.global gdt_flush
gdt_flush:
    mov 4(%esp), %eax    # Get the gdt_ptr
    lgdt (%eax)          # Load the GDT

    mov $0x10, %ax       # 0x10 -> Offset of the Data Segment (Index 2)
    mov %ax, %ds         # Update data segments
    mov %ax, %es
    mov %ax, %fs
    mov %ax, %gs
    mov %ax, %ss

    # Update CS (Code Segment) !
    ljmp $0x08, $.flush 

.flush:
    ret                  # Go back to C code