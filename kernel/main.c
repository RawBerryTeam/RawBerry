/* 
 * ---------------------------------------------------------------
 *                            RawBerry
 * (c) RawBerry Team
 * Published on license MIT. Read `/LICENSE` for more details.
 * ---------------------------------------------------------------
*/

// these checks just ensure you use a cross-compiler
// in case you dont, your system probably wont work
#if defined(__linux__)
#error "Use a cross-compiler for ix86"
#endif

// 32bit targets
#if !defined(__i386__)
#error "Use a cross-compiler for elf32-i386"
#endif

#include "main.h"
#include "../drivers/vga.h"
#include "../drivers/port.h"
#include "../drivers/keyboard.h"
#include "../include/stdio.h" // :: There is no standard yet, either switch to "stdio.h" or comment it out until
//                               :: there is implementation for it

void launch_kernel(void) {
    vga_initialize();
    printf("kernel init")
    print_log(); //hehehe
    vga_print_string("Welcome to RawBerry OS!\n");
    while (1)
    {
        keyboard_handler();
    }
}
