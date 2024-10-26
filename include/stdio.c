#include "stdio.h"
#include "../drivers/vga.h"
#include "../kernel/terminal.h"

void printf(char* text) {
    /*
    VERY IMPORTANT TO NOTE:
    
    ANSI escapes are not avaliable while the kernel is still in it's baby state.
    VGA color can probably be implemented using a little more code, but let's be conservative
    while the system is in it's baby stages.
    */
    vga_print_string(text);
}

char *scanf() {
    // See terminal.h in kernel for implementation
    return scan();
}