#ifndef VGA_H
#define VGA_H

#include <stdint.h>
#include <stddef.h>

#define VGA_WIDTH 80
#define VGA_HEIGHT 25
#define VGA_ADDRESS 0xB8000

// Color definitions
enum vga_color {
    VGA_COLOR_BLACK = 0,
    VGA_COLOR_BLUE = 1,
    VGA_COLOR_GREEN = 2,
    VGA_COLOR_CYAN = 3,
    VGA_COLOR_RED = 4,
    VGA_COLOR_MAGENTA = 5,
    VGA_COLOR_BROWN = 6,
    VGA_COLOR_LIGHT_GREY = 7,
    VGA_COLOR_DARK_GREY = 8,
    VGA_COLOR_LIGHT_BLUE = 9,
    VGA_COLOR_LIGHT_GREEN = 10,
    VGA_COLOR_LIGHT_CYAN = 11,
    VGA_COLOR_LIGHT_RED = 12,
    VGA_COLOR_LIGHT_MAGENTA = 13,
    VGA_COLOR_LIGHT_BROWN = 14,
    VGA_COLOR_WHITE = 15,
};

extern uint16_t* vga_buffer;
extern uint8_t vga_color;
extern uint16_t vga_row;
extern uint16_t vga_column;

uint16_t vga_entry(unsigned char uc, uint8_t color);
void vga_initialize(void);
void vga_print_string(const char* str);
void vga_put_char(char c);
void vga_putentryat(char c, uint8_t color, size_t x, size_t y);
void vga_clear_screen(void);
void vga_update_cursor(uint16_t x, uint16_t y);
#endif  // VGA_H
