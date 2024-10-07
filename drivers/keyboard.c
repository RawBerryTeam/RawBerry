#include "keyboard.h"
#include "vga.h"
#include "port_io.h"

unsigned char keyboard_map[128] = {
    0,  27, '1', '2', '3', '4', '5', '6', '7', '8', /* 9 */
    '9', '0', '-', '=', '\b', /* Backspace */
    '\t', /* Tab */
    'q', 'w', 'e', 'r', /* 19 */
    't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n', /* Enter */
    0, /* Control */
    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', /* 39 */
    '\'', '`',   0, /* Left shift */
    '\\', 'z', 'x', 'c', 'v', 'b', 'n', /* 49 */
    'm', ',', '.', '/',   0, /* Right shift */
    '*', 0,  /* Alt */
    ' ',  /* Space bar */
    0,  /* Caps lock */
    /* F1 - F10 */
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    /* Num lock */
    0,  /* Scroll Lock */
    0,  /* Home key */
    0,  /* Up Arrow */
    0,  /* Page Up */
    '-',
    0,  /* Left Arrow */
    0,
    0,  /* Right Arrow */
    '+',
    0,  /* End key */
    0,  /* Down Arrow */
    0,  /* Page Down */
    0,  /* Insert Key */
    0,  /* Delete Key */
    0, 0, 0, 0,  /* F11, F12 */
    0, /* Undefined keys */
};

void vga_print_char(char c) {
    char str[2] = {c, '\0'};
    vga_print_string(str);
}

void keyboard_handler() {
    unsigned char status;
    char keycode;

    status = inb(0x64);
    
    if (status & 0x01) {
        keycode = inb(0x60);  

        if (keycode > 0) {
            char znak = keyboard_map[(unsigned char)keycode];
            if (znak) {
                vga_print_char(znak);  
            }
        }
    }
}

void init_keyboard() {
    register_interrupt_handler(IRQ1, keyboard_handler);
}
