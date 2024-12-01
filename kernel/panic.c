/* 
 * ---------------------------------------------------------------
 *                            RawBerry
 * (c) RawBerry Team
 * Published on license MIT. Read `/LICENSE` for more details.
 * ---------------------------------------------------------------
*/

#include <stdbool.h>
#include "../drivers/vga.h"

/**
 * Stops every single process and frozes the system.
 */
void kernel_panic(const char* msg) {
    vga_initialize();
    vga_color = 12;
    vga_print_string("Kernel panic! ");
    vga_print_string(msg);
    while (true) {}
}