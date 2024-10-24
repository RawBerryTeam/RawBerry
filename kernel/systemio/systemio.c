#include "systemio.h"
#include "../drivers/vga.h"

void out(char* PROCESS_NAME, char* OUT_TYPE, char* TEXT) {
    // May be pretty stupid to make the output look pretty, but it will be way better
    // when trying to debug.

    vga_print_string(("[%s/%s]: %s", PROCESS_NAME, OUT_TYPE, TEXT)); // just to be safe, double ()()
}