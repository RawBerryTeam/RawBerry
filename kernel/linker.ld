OUTPUT_FORMAT("elf32-i386")
ENTRY(init_system)

SECTIONS
{
    . = 0x400000;

    .multiboot :
    {
        KEEP(*(.multiboot))
    }
    
    .text : {
        *(.text)
    }

    .rodata : {
        *(.rodata) 
    }

    .data : {
        *(.data)  
    }

    .bss : {
        *(.bss)
    }

    .debug : {
        *(.debug.*)
    }

    /DISCARD/ : {
        *(.comment)
        *(.note)
    }
}