#include "../drivers/vga.h"

void keyboard_handler(void);
void append_char(char* str, char c, size_t* len, size_t max_len);
void handle_keypress(char c);
void keyboard_isr(void);
void delay(uint32_t milliseconds);
void getInput(char *output);
void clear_buffer();
size_t strlen(const char* str);
char* readStr();