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
#include "../include/String.h"
#include "test.h"
#include "ih/terminal.h"
#include "../include/stdio.h" // :: There is no standard yet, either switch to "stdio.h" or comment it out until
//                               :: there is implementation for it

void launch_kernel(void) {
    int resturn;
    resturn = run();
    if(resturn == 1){
        vga_clear_screen();
        kernel_panic("SOMETHING WRONG/BAD HAPPENED");
    }
}
