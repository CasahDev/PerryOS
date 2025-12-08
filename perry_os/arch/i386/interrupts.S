.global _isr_wrapper
.extern isr_handler
_isr_wrapper:
    # Push all the registers in the stack
    pusha 

    pushl %esp # Add the parameters of the isr_handler function
    call isr_handler # Call the isr_handler C function

    add $4, %esp # Add 4 to the stack top pointeur value

    popa # Pop all the stack into registers
    iret # End the function