#include <stddef.h>
#include <stdint.h>
#include "../drivers/keyboard.h"
#define PIT_BASE 0x43 // PIT Control Register
#define PIT_CHANNEL0 0x40 // Channel 0 Data Port
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

void pit_init(uint32_t frequency) {
    // Set PIT to the desired frequency
    uint32_t divisor = 1193180 / frequency; // PIT frequency is 1193180 Hz
    outb(PIT_BASE, 0x36); // Set mode: square wave generator
    outb(PIT_CHANNEL0, divisor & 0xFF); // Set low byte
    outb(PIT_CHANNEL0, (divisor >> 8) & 0xFF); // Set high byte
}

void delay(uint32_t milliseconds) {
    // Convert milliseconds to frequency ticks
    pit_init(1000); // Set PIT for 1000 Hz (1 tick = 1 ms)
    
    for (uint32_t i = 0; i < milliseconds; i++) {
        // Wait for one tick
        while ((inb(PIT_CHANNEL0) & 0x01) == 0) {
            // Wait until the PIT generates an interrupt
        }
    }
}

char input_char[256];
size_t input_len = 0;              // Current length of the input
/* Keyboard scancode mapping (partial, for simplicity) */
void clear_buffer(){
    input_len = 0;
    for (size_t i = 0; i < strlen(input_char); i++) {
        input_char[i] = '\0'; // Set each character to null
    }
    vga_print_string("\n");  
}

static inline void outw(uint16_t port, uint16_t val) {
    __asm__ volatile ("outw %0, %1" : : "a"(val), "Nd"(port));
}
void append_char(char* str, char c, size_t* len, size_t max_len) {
    if (*len + 1 < max_len) {
        str[*len] = c;      // Add the new character at the end
        (*len)++;           // Update the length of the string
        str[*len] = '\0';   // Add the null-terminator
    }
}

static const char scancode_to_char[] = {
    0,  27, '1', '2', '3', '4', '5', '6', '7', '8',    /* 0x00 - 0x09 */
    '9', '0', '-', '=', '\b', /* Backspace */
    '\t', /* Tab */
    'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n', /* Enter key */
    0,    /* Control key */
    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`',
    0,    /* Left shift */
    '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/',
    0,    /* Right shift */
    '*',
    0,    /* Alt */
    ' ',  /* Space bar */
    0,    /* Caps lock */
    /* F1 - F12 keys not mapped here for simplicity */
};
void remove_last_char(char* str, size_t* len) {
    if (*len > 0) {
        (*len)--;  // Decrease the length
        str[*len] = '\0';  // Null-terminate after removal
    }
}
void handle_keypress(char c) {
	if (c == '\n') {  // Check if the Enter key was pressed
        // Process the input stored in input_buffer (e.g., print it)
        vga_print_string("\n");  
        clear_buffer();         // New line after the input
        input_len = 0;  // Reset input length for new input
        return;  // Don't add the newline character to the buffer
    }else if (c == '\b') {  // Backspace
        if (input_len > 0) {
            remove_last_char(input_char, &input_len);  // Remove last character from input buffer
            
            // Update terminal position
            if (vga_column > 0) {
                vga_column--;
            } else if (vga_row > 0) {
                vga_row--;
                vga_column = VGA_WIDTH - 1;
            }

            // Clear the character on the screen by overwriting with a space
            vga_putentryat(' ', vga_color, vga_column, vga_row);
        }
        return;
    }

    append_char(input_char, c, &input_len, 256);
    vga_put_char(c);  // Display the key on the screen

}
void myStrCopy(char *destination, const char *source) {
    while (*source) {         // While we haven't reached the end of the source string
        *destination++ = *source++; // Copy each character
    }
    *destination = '\0';     // Null-terminate the destination string
}

void getInput(char *output){
    myStrCopy(output,input_char);

}

void keyboard_handler(void) {
    uint8_t scancode = inb(0x60);
    
    if (scancode < sizeof(scancode_to_char)) {
        char key = scancode_to_char[scancode];
        if (key) {
            handle_keypress(key);  // Handle the keypress by storing the char and displaying it
        }
    }
	delay(180000);
}


/* Interrupt Service Routine for keyboard */
void keyboard_isr(void) {
    keyboard_handler();
    
    // Send End of Interrupt (EOI) signal to PIC
    outb(0x20, 0x20);
}
char Printch(char c) {
    if (c == '\b') { // Backspace handling
        if (vga_column > 0) {
            vga_column--; // Move cursor back in the same row
        } else if (vga_row > 0) {
            vga_row--;                 // Move up one row
            vga_column = VGA_WIDTH - 1; // Set to last column of the previous row
        }
        vga_putentryat(' ', vga_color, vga_column, vga_row); // Clear character
    } else {
        vga_put_char(c); // Normal character printing
    }
    return c;
}

char* readStr() {
    static char buffstr[256];  // Buffer to hold the input string, with a size limit
    uint8_t i = 0;
    uint8_t reading = 1;

    while (reading) {
        if (inb(0x64) & 0x1) {
            switch (inb(0x60)) {
                case 2: Printch('1'); buffstr[i++] = '1'; break;
                case 3: Printch('2'); buffstr[i++] = '2'; break;
                case 4: Printch('3'); buffstr[i++] = '3'; break;
                case 5: Printch('4'); buffstr[i++] = '4'; break;
                case 6: Printch('5'); buffstr[i++] = '5'; break;
                case 7: Printch('6'); buffstr[i++] = '6'; break;
                case 8: Printch('7'); buffstr[i++] = '7'; break;
                case 9: Printch('8'); buffstr[i++] = '8'; break;
                case 10: Printch('9'); buffstr[i++] = '9'; break;
                case 11: Printch('0'); buffstr[i++] = '0'; break;
                case 12: Printch('-'); buffstr[i++] = '-'; break;
                case 13: Printch('='); buffstr[i++] = '='; break;
                case 14: // Backspace handling
                    if (i > 0) {
                        Printch('\b'); // Move cursor back
                        i--;          // Decrease index
                        buffstr[i] = 0; // Null-terminate the string
                    }
                    break;
                case 15: // Tab key (insert 4 spaces)
                    for (uint8_t j = 0; j < 4 && i < 255; j++) {
                        buffstr[i++] = ' ';
                        Printch(' '); // Print space
                    }
                    break;
                case 16: Printch('q'); buffstr[i++] = 'q'; break;
                case 17: Printch('w'); buffstr[i++] = 'w'; break;
                case 18: Printch('e'); buffstr[i++] = 'e'; break;
                case 19: Printch('r'); buffstr[i++] = 'r'; break;
                case 20: Printch('t'); buffstr[i++] = 't'; break;
                case 21: Printch('y'); buffstr[i++] = 'y'; break;
                case 22: Printch('u'); buffstr[i++] = 'u'; break;
                case 23: Printch('i'); buffstr[i++] = 'i'; break;
                case 24: Printch('o'); buffstr[i++] = 'o'; break;
                case 25: Printch('p'); buffstr[i++] = 'p'; break;
                case 26: Printch('['); buffstr[i++] = '['; break;
                case 27: Printch(']'); buffstr[i++] = ']'; break;
                case 28: // Enter key
                    buffstr[i] = '\n';
                    i++;
                    buffstr[i] = 0;
                    Printch('\n');
                    reading = 0; // Exit the loop
                    break;
                case 29: // Left Control key
                    // Handle if needed
                    break;
                case 30: Printch('a'); buffstr[i++] = 'a'; break;
                case 31: Printch('s'); buffstr[i++] = 's'; break;
                case 32: Printch('d'); buffstr[i++] = 'd'; break;
                case 33: Printch('f'); buffstr[i++] = 'f'; break;
                case 34: Printch('g'); buffstr[i++] = 'g'; break;
                case 35: Printch('h'); buffstr[i++] = 'h'; break;
                case 36: Printch('j'); buffstr[i++] = 'j'; break;
                case 37: Printch('k'); buffstr[i++] = 'k'; break;
                case 38: Printch('l'); buffstr[i++] = 'l'; break;
                case 39: Printch(';'); buffstr[i++] = ';'; break;
                case 40: Printch('\''); buffstr[i++] = '\''; break; // Single quote
                case 41: Printch('`'); buffstr[i++] = '`'; break;   // Backtick
                case 42: // Left Shift key
                    // Handle if needed
                    break;
                case 43: Printch('\\'); buffstr[i++] = '\\'; break; // Backslash
                case 44: Printch('z'); buffstr[i++] = 'z'; break;
                case 45: Printch('x'); buffstr[i++] = 'x'; break;
                case 46: Printch('c'); buffstr[i++] = 'c'; break;
                case 47: Printch('v'); buffstr[i++] = 'v'; break;
                case 48: Printch('b'); buffstr[i++] = 'b'; break;
                case 49: Printch('n'); buffstr[i++] = 'n'; break;
                case 50: Printch('m'); buffstr[i++] = 'm'; break;
                case 51: Printch(','); buffstr[i++] = ','; break;
                case 52: Printch('.'); buffstr[i++] = '.'; break;
                case 53: Printch('/'); buffstr[i++] = '/'; break;
                case 54: // Right Shift key
                    // Handle if needed
                    break;
                case 55: // Numeric pad
                    break;
                case 56: Printch(' '); buffstr[i++] = ' '; break; // Space key
                case 57: Printch(' '); buffstr[i++] = ' '; break; // Another space key (for different keycode)
                default: break; // Ignore other keycodes
            }
            
        }
        
    }
    return buffstr;
}