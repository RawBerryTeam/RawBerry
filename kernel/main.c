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
#include <stdio.h>

void launch_kernel(void) {
    vga_initialize();
    vga_print_string("Kernel loaded.\n");
    print_log(); //hehehe
    vga_print_string("Welcome RawBerry!\n");
    while (1)
    {
        keyboard_handler();
    }
    
}
