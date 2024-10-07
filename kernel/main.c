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
    sleep(10000);
    // Poor VGA...
    vga_print_string("Testing colors...");
    vga_color = 1;
    vga_initialize();
    vga_print_string("Blue\n");
    sleep(10000);
    vga_color = 2;
    vga_initialize();
    vga_print_string("Green\n");
    sleep(10000);
    vga_color = 3;
    vga_initialize();
    vga_print_string("Cyan\n");
    sleep(10000);
    vga_color = 4;
    vga_initialize();
    vga_print_string("Red\n");
    sleep(10000);
    vga_color = 5;
    vga_initialize();
    vga_print_string("Magenta\n");
    sleep(10000);
    vga_color = 6;
    vga_initialize();
    vga_print_string("Brown\n");
    sleep(10000);
    vga_color = 7;
    vga_initialize();
    vga_print_string("Light gray\n");
    sleep(10000);
    vga_color = 8;
    vga_initialize();
    vga_print_string("Dark gray\n");
    sleep(10000);
    vga_color = 9;
    vga_initialize();
    vga_print_string("Light blue\n");
    sleep(10000);
    vga_color = 10;
    vga_initialize();
    vga_print_string("Light green\n");
    sleep(10000);
    vga_color = 11;
    vga_initialize();
    vga_print_string("Light cyan\n");
    sleep(10000);
    vga_color = 12;
    vga_initialize();
    vga_print_string("Light red\n");
    sleep(10000);
    vga_color = 13;
    vga_initialize();
    vga_print_string("Light magenta\n");
    sleep(10000);
    vga_color = 14;
     vga_initialize();
    vga_print_string("Light brown\n");
    sleep(10000);
    vga_color = 15;
    vga_initialize();
    vga_print_string("White\n");
    sleep(10000);
    vga_initialize();
    // This is stupid, since I have to reload this driver eh... atleast it works!
    vga_print_string("Testing completed... Let the VGA driver rest...\n");
    vga_print_string("If you didn't saw colors that were named on the screen, then RIP your video cable or driver\n");
    vga_print_string("End of kernel code.\n");
    vga_print_string("user.host > ");
}

