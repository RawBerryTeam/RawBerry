#include "systemio.h"
#include "../drivers/vga.h"

void out(char* PROCESS_NAME, SYSTEMIO_OUT_TYPE OUT_TYPE, char* TEXT) {
    // May be pretty stupid to make the output look pretty, but it will be way better
    // when trying to debug.

    switch (OUT_TYPE) {
        case 1:
            vga_print_string(("[%s/info]: %s", PROCESS_NAME, TEXT)); // just to be safe, double ()()
            break;
        case 2:
            vga_print_string(("[%s/warn]: %s", PROCESS_NAME, TEXT)); // just to be safe, double ()()
            break;
        case 3:
            vga_print_string(("[%s/error]: %s", PROCESS_NAME, TEXT)); // just to be safe, double ()()
            break;
        case 4:
            vga_print_string(("[%s/kernel panic]: %s", PROCESS_NAME, TEXT));
            break;
        default:
            vga_print_string(("[systemio/error]: process %s invoked standard incorrectly with OUT_TYPE", PROCESS_NAME));
            break;
    }
}
