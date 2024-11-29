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
#include "../include/string.h"
#include "../include/stdio.h" // :: There is no standard yet, either switch to "stdio.h" or comment it out until
//                               :: there is implementation for it

void launch_kernel(void) {
    vga_initialize();
    vga_print_string("Welcome to RawBerry OS!\n");
    char* temp;
    while (1)
    {
        vga_print_string("> ");
        temp = readStr();
        if (strEql(strSlice(temp, 0, 4), "echo") == 0) {
            char* sliced = strSlice(temp, 5, Strlen(temp));
            vga_print_string(sliced);
        }
    }
}
