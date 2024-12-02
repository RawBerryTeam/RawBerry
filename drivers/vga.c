/* 
 * ---------------------------------------------------------------
 *                            RawBerry
 * (c) RawBerry Team 
 * Published on license MIT. Read `/LICENSE` for more details.
 * ---------------------------------------------------------------
*/

#include "vga.h"
#include <stddef.h>
static inline void outb(uint16_t port, uint8_t value) {
    __asm__ volatile (
        "outb %0, %1"
        :
        : "a"(value), "Nd"(port)
    );
}

// Function to read from an I/O port
static inline uint8_t inb(uint16_t port) {
    uint8_t ret;
    __asm__ volatile (
        "inb %1, %0"
        : "=a"(ret)
        : "Nd"(port)
    );
    return ret;
}
uint16_t* vga_buffer = (uint16_t*)VGA_ADDRESS;
uint8_t vga_color = VGA_COLOR_LIGHT_GREY | (VGA_COLOR_BLACK << 4);
uint16_t vga_row = 0;
uint16_t vga_column = 0;

uint16_t vga_entry(unsigned char uc, uint8_t color) {
    return (uint16_t)(uc | (color << 8));
}

void vga_initialize(void) {
    for (int y = 0; y < VGA_HEIGHT; y++) {
        for (int x = 0; x < VGA_WIDTH; x++) {
            vga_buffer[y * VGA_WIDTH + x] = vga_entry(' ', vga_color);
        }
    }
}

void vga_set_color(uint8_t color) {
    vga_color = color;
}

void vga_put_char(char c) {
    if (c == '\n') {
        vga_row++;
        vga_column = 0;
        return;
    }
    if (c == '\0') {
        c = ' ';  // Replace with a space
    }
    vga_buffer[vga_row * VGA_WIDTH + vga_column] = vga_entry(c, vga_color);
    if (++vga_column == VGA_WIDTH) {
        vga_column = 0;
        if (++vga_row == VGA_HEIGHT) {
            vga_row = 0;
        }
    }
    vga_update_cursor(vga_column, vga_row);
}

void vga_print_string(const char* str) {
    for (size_t i = 0; str[i] != '\0'; i++) {
        vga_put_char(str[i]);
    }
}
void vga_putentryat(char c, uint8_t color, size_t x, size_t y) 
{
	const size_t index = y * VGA_WIDTH + x;
	vga_buffer[index] = vga_entry(c, color);
}
void vga_clear_screen(void) {
    for (int y = 0; y < VGA_HEIGHT; y++) {
        for (int x = 0; x < VGA_WIDTH; x++) {
            vga_buffer[y * VGA_WIDTH + x] = vga_entry(' ', vga_color);
        }
    }
    // Reset the cursor to the top-left corner
    vga_row = 0;
    vga_column = 0;
}

void vga_clear_line(uint16_t line) {
    if (line >= VGA_HEIGHT) {
        return; 
    }

    for (int x = 0; x < VGA_WIDTH; x++) {
        vga_buffer[line * VGA_WIDTH + x] = vga_entry(' ', vga_color);
    }
}
void vga_update_cursor(uint16_t x, uint16_t y) {
    uint16_t cursor_pos = y * VGA_WIDTH + x;

    // Send the cursor position to the VGA hardware (usually through ports)
    // Cursor High byte
    outb(0x3D4, 0x0E);  // Select the high byte of the cursor
    outb(0x3D5, (uint8_t)(cursor_pos >> 8));

    // Cursor Low byte
    outb(0x3D4, 0x0F);  // Select the low byte of the cursor
    outb(0x3D5, (uint8_t)(cursor_pos & 0xFF));
}
