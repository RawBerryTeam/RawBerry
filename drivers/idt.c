#include "idt.h"

void (*interrupt_handlers[256])();

void register_interrupt_handler(int n, void (*handler)()) {
    interrupt_handlers[n] = handler;
}

void isr_handler() {
    if (interrupt_handlers[IRQ1]) {
        interrupt_handlers[IRQ1]();  
    }
}
