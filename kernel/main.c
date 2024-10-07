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
#include <stdio.h>

void launch_kernel(void) {
    vga_initialize();
    vga_print_string("Kernel loaded.\n");
    print_log();
    vga_print_string("Welcome RawBerry kernel! (v1.0.1a)\n");
    // First every RawBerry app (kind off) 
    vga_print_string("Loading VGA test...");
    vga_print_string("TESTING VGA: !@#$% Unicode is not supported...\n");
    wait(10);
    // Poor VGA...
    vga_print_string("Changing color...");
    vga_color = 1;
    wait(10);
    vga_color = 2;
    wait(10);
    vga_color = 3;
    wait(10);
    vga_color = 4;
    wait(10);
    vga_color = 5;
    wait(10);
    vga_color = 6;
    wait(10);
    vga_color = 7;
    wait(10);
    vga_color = 8;
    wait(10);
    vga_color = 9;
    wait(10);
    vga_color = 10;
    wait(10);
    vga_color = 11;
    wait(10);
    vga_color = 12;
    wait(10);
    vga_color = 13;
    wait(10);
    vga_color = 14;
    wait(10);
    vga_color = 15;
    wait(10);
    vga_print_string("Testing completed... Let the VGA driver rest...");
    vga_print_string("End of kernel code.");
    vga_print_string("user.host > ");
}
