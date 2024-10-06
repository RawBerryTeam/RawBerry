ifeq ($(OS),Windows_NT)
$(error lmao compiling on windows is not allowed)
endif

ISO_NAME = system.iso
SRC_DIR = ./
INCLUDE_DIR = ./include
BUILD_DIR = build
ISO_DIR = ./
GRUB_DIR = $(ISO_DIR)/boot/grub
GRUB_CFG = $(GRUB_DIR)/grub.cfg
CC = gcc
CFLAGS = -Wall -Wextra -nostdlib -I$(INCLUDE_DIR)
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

LD = ld
LDFLAGS = -T linker.ld

all: iso clean

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

kernel.bin: $(OBJS)
	$(LD) $(LDFLAGS) -o kernel.bin $(OBJS)

iso: kernel.bin grub_cfg
	mkdir -p $(ISO_DIR)/boot
	cp kernel.bin $(ISO_DIR)/boot/
	grub-mkrescue -o $(ISO_NAME) $(ISO_DIR)

grub_cfg:
	mkdir -p $(GRUB_DIR)
	cp boot/grub/grub.cfg $(GRUB_CFG)

clean:
	rm -rf $(BUILD_DIR) kernel.bin

.PHONY: all clean iso grub_cfg