#include "../drivers/vga.h"
#include "../drivers/port.h"
#include "../drivers/keyboard.h"
#include "../include/String.h"
#include "../include/stdio.h"
#include "ascii.h"

char* commands[] = {
    "echo", "prints argument", // 0 1
    "clear", "clears screen", // 2 3
    "help", "display help", // 4 5
    "logo", "shows rawberry logo", // 6 7
    "about", "about the os"
};
void display() {
    for (int i = 0; i < 5; i++) {  
        vga_print_string(commands[i * 2]);   
        vga_print_string(": ");
        vga_print_string(commands[i * 2 + 1]); 
        vga_print_string("\n");
    }
}

int run() {
    vga_initialize();
    vga_print_string("Welcome to RawBerry OS!\n");

    char* temp;
    while (1) {
        vga_print_string("> ");
        temp = readStr();
        if (strEql(strSlice(temp, 0, 4), "echo") == 0) {
            char* sliced = strSlice(temp, 5, Strlen(temp));
            vga_print_string(sliced);
        } else if (strEql(strSlice(temp, 0, 5), "clear") == 0) {
            vga_clear_screen();
        } else if (strEql(strSlice(temp, 0, 4), "help") == 0) {
            display();
        } else if (strEql(strSlice(temp, 0, 4), "logo") == 0) {
            logo();
        } else if (strEql(strSlice(temp, 0, 5), "about") == 0) {
            print_info();
        }
    }
    return 0;
}
