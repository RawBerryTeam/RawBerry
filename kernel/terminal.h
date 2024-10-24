/*
Terminal jobs. This should be mostly:
- I/O (input / output)
- Writing stuff

Any more should be placed in a seperate header file.
*/

#include "../drivers/keyboard.h"
#include "systemio.h"

void callback(char *input) {
    // *input is the result (is called when user selects enter)
    // when creating raw mode terminals, we need to change this to support it

    vga_print_string(input); // we'll just print it extra for now
}

void InitTerminal() {
    out("rterminal", SYSTEMIO_OUT_INFO, "terminal is init");
    
    while (1) {
        keypress_handler(callback); // handle keypress, will send to callback()
    }
}