/*
Terminal jobs. This should be mostly:
- I/O (input / output)
- Writing stuff

Any more should be placed in a seperate header file.
*/

#include "../drivers/keyboard.h"
#include "systemio.h"

void callback(char input) {
    //      // *input is the result (is called when user selects enter)
    //      // when creating raw mode terminals, we need to change this to support it

    // above should now be fixed, callback will handle each character pressed

    out("rterminal", SYSTEMIO_OUT_INFO, ("new input received: %s", input)); // we'll just print it extra for now

    // here are some quick escape code reminders:
    //  \n : ENTER key
    //  \b : BACKSPACE key
}

void InitTerminal() {
    out("rterminal", SYSTEMIO_OUT_INFO, "terminal is init");
    
    while (1) {
        keypress_handler(callback); // handle keypress, will send to callback()
    }
}