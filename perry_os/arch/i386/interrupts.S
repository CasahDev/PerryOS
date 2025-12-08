.extern isr_handler

.global _isr_wrapper
_isr_wrapper:
# Push all the registers in the stack
pusha 

// Call the isr_handler C function
call isr_handler

// Pop all the stack into registers
popa

// End the function
iret