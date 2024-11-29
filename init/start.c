/* 
 * ---------------------------------------------------------------
 *                            RawBerry
 * (c) RawBerry Team 
 * Published on license MIT. Read `/LICENSE` for more details.
 * ---------------------------------------------------------------
*/

#include <declarations.h>
#include "../drivers/vga.h"

void _start() {
    vga_initialize();
    vga_color = 11;
    vga_print_string("[ Booting kernel ]\n");
    vga_color = 15;
    launch_kernel();
    return;
}