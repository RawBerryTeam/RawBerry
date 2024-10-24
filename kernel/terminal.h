/*
Terminal jobs. This should be mostly:
- I/O (input / output)
- Writing stuff

Any more should be placed in a seperate header file.
*/

#ifndef TERMINAL_H_
#define TERMINAL_H_

#include "../drivers/keyboard.h"
#include "systemio.h"

int scanning = 0;

char scan_txt[256] = "";

char *scan() {
    // helps us implement scanf() !!!
    scanning = 1;

    while (scanning == 1) {
        if (scanning == 0) {
            break; // exit when scanning ends
        }
    }

    return scan_txt;
}

void callback(char input) {
    //      // *input is the result (is called when user selects enter)
    //      // when creating raw mode terminals, we need to change this to support it

    // above should now be fixed, callback will handle each character pressed

    if (scanning = 1) {
        if (input == "\n") {
            scan_txt[sizeof(scan_txt) + 1] = '\0'; // finish the string off and ship it to poland
            scanning = 0;
        } else if (input == "\b") {
            scan_txt[sizeof(scan_txt)] = ''; // remove the current character from it
        } else {
            scan_txt[sizeof(scan_txt) + 1] = input; // scary! willfix
        }
    }

    // helpful debug information
    // out("rterminal", SYSTEMIO_OUT_INFO, ("new input received: %s", input)); // we'll just print it extra for now

    // here are some quick escape code reminders:
    //  \n : ENTER key
    //  \b : BACKSPACE key
}

void init_terminal() {
    out("rterminal", SYSTEMIO_OUT_INFO, "terminal is init");
    keypress_handler(callback); // handle keypress, will send to callback()
}

#endif