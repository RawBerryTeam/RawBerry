/* 
 * ---------------------------------------------------------------
 *                            RawBerry
 * (c) RawBerry Team
 * Published on license MIT. Read `/LICENSE` for more details.
 * ---------------------------------------------------------------
*/
#include "main.h"
#include "../drivers/vga.h"
#include "../drivers/port.h"
#include "../drivers/keyboard.h"
#include "../include/stdio.h" // :: There is no standard yet, either switch to "stdio.h" or comment it out until
//                               :: there is implementation for it

void launch_kernel(void) {
    vga_initialize();
    out("kernel", SYSTEMIO_OUT_INFO, "Kernel has initialized");
    print_log(); //hehehe
    vga_print_string("Welcome to RawBerry OS!\n");
    while (1)
    {
        keyboard_handler();
    }
}
