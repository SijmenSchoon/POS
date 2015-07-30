.global isr_wrapper
isr_wrapper:
    pushal
    cld
    call interrupt_handler
    popal
    iret
