#include "../include/string.h"

char* itol(int num) {
    static char buffer[32];
    int i = 30;

    if (num == 0) buffer[i--] = '0';

    if (num < 0) {
        buffer[i--] = '-';
        num = -num;
    }

    while (num > 0) {
        buffer[i--] = num % 10 + '0';
        num /= 10;
    }

    return &buffer[i + 1];
}

int stol(const char* str) {
    int result = 0;

    while (*str) {
        result = result * 10 + (*str++ - '0');
    }

    return result;
}
