OUTPUT_ARCH( "riscv" )
ENTRY( _start )
SECTIONS
{
  /* text: test code section */
  . = 0x80000000;
  .text : { 
    *(.reset) 
    *(.text) 
  }
  /* data: Initialized data segment */
  . = 0x90000000;
  .data : { *(.data) }
  .rodata : { *(.rodata) }
  .sdata : { *(.sdata) }
  .sbss : {
    . = ALIGN(16);
    PROVIDE(_bss_start = .);
    *(.sbss .sbss.*)
  }
  .bss :{
    *(.bss .bss.*)
    . = ALIGN(16);
    PROVIDE(_bss_end = .);
  }
  .debug : { *(.debug) }
  . += 0x8000;
  stack_top = .;

  /* End of uninitalized data segement */
  _end = .;
}
