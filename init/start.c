/* 
 * ---------------------------------------------------------------
 *                            RawBerry
 * (c) RawBerry Team 
 * Published on license MIT. Read `/LICENSE` for more details.
 * ---------------------------------------------------------------
*/

#include <declarations.h>
#include "../drivers/vga.h"

void init_system() {
    vga_initialize();
    vga_color = 11;
    vga_print_string("[ Booting kernel ]");
    vga_color = 15;
    launch_kernel();
    return;
}