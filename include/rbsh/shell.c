#include "../stdio.h"
#include "shell.h"

#define DUMMY_USERNAME = "redberry"
#define DUMMY_HOSTNAME = "rawberry"

void RAWBERRY_VERSION() {
    printf("RawBerry Operating System v1.0.0\n");
    printf("(C) Copyright 2024 RawBerry Team\n");
    printf("Licensed under the MIT License.\n\n");
    printf("RawBerry Shell v1.0.0\n");
    printf("(C) Copyright 2024 Ben Daws <ben@bendaws.net>\n");
    printf("Licensed under the MIT License.\n")
}

void shell_loop() {
    printf(("%s@%s : $ ", DUMMY_USERNAME, DUMMY_HOSTNAME)); // with default dummy stuff, it looks
    // redberry@rawberry : $ (command)
    char *command = scanf();

    if (command == "about") {
        RAWBERRY_VERSION();
    } else {
        printf("%s is not the name of an executable, macro, or system function.\n");
    }
}