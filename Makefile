all:
	riscv32-unknown-elf-gcc -g -T src/link.ld src/start.s src/main.c -o martos -mabi=ilp32 -fPIC -nostdlib -nostartfiles
