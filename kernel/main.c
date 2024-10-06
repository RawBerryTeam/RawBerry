/* 
 * ---------------------------------------------------------------
 *                            RawBerry
 * (c) RawBerry Team
 * Published on license MIT. Read `/LICENSE` for more details.
 * ---------------------------------------------------------------
*/
#include "main.h"
#include "../drivers/vga.h"

/**
 * Launches kernel.
 */
void launch_kernel(void) {
    vga_initialize();
    vga_print_string("Hello, RawBerry OS!\n");
    vga_print_string("Welcome to your custom kernel.");
}