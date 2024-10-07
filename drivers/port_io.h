#ifndef PORT_IO_H
#define PORT_IO_H

unsigned char inb(unsigned short port);
void outb(unsigned short port, unsigned char data);

#endif
