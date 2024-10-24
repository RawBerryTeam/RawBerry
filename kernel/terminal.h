/*
Terminal jobs. This should be mostly:
- I/O (input / output)
- Writing stuff

Any more should be placed in a seperate header file.
*/

#include "../drivers/keyboard.h"
#include "systemio.h"

void step(void keypress_handler) {
    keypress_handler(); // handle keypress
}

void InitTerminal() {
    out("rterminal", SYSTEMIO_OUT_INFO, "terminal is init");
    
    while (1) {
        step(keyboard_handler);
    }
}