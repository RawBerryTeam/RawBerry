ifeq ($(OS),Windows_NT)
$(error You can only build this on Linux)
endif

CC = gcc -m32 -nostartfiles
CFLAGS = -ffreestanding -nostdlib -Iinclude
LDFLAGS = -T ./kernel/linker.ld
OBJS = $(patsubst %.c,%.o,$(wildcard **/*.c))
KERNEL = kernel.elf
ISO = rawberry.iso

all: $(ISO)

compile: $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(KERNEL): compile
	$(CC) $(LDFLAGS) $(OBJS) -o $(KERNEL)

$(ISO): $(KERNEL)
	mkdir -p iso/boot/grub
	cp $(KERNEL) iso/boot/kernel.elf 
	cp ./boot/grub/grub.cfg iso/boot/grub/
	grub-mkrescue -o $(ISO) iso

run: $(ISO)
	qemu-system-i386 -cdrom $(ISO)

clean:
	rm -f $(OBJS) $(KERNEL) $(ISO)
	rm -rf iso