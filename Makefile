rawberry:
	i686-elf-as boot.s -o boot.o
	i686-elf-gcc -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	i686-elf-gcc -T linker.ld -o myos.bin -ffreestanding -O2 -nostdlib boot.o kernel.o -lgcc

	mkdir -p boot
	mkdir -p boot/grub
	cp myos.bin boot/myos.bin
	cp grub.cfg boot/grub/grub.cfg
	grub-mkrescue -o rawb.iso boot

check_multiboot:
	if grub-file --is-x86-multiboot rawb.bin; then
  		echo multiboot confirmed
	else
  		echo the file is not multiboot
	fi