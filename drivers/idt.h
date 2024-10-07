#ifndef IDT_H
#define IDT_H

void register_interrupt_handler(int n, void (*handler)());
void isr_handler();

#endif