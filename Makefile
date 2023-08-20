all:
	riscv32-unknown-elf-gcc -c -g -o build/start.o src/start.s -march=rv32i_zicsr -mabi=ilp32 -fPIC -nostdlib -nostartfiles
	riscv32-unknown-elf-gcc -c -g -o build/timer_handler.o src/kernel/timer_handler.s -march=rv32i_zicsr -mabi=ilp32 -fPIC -nostdlib -nostartfiles
	riscv32-unknown-elf-gcc -c -g -o build/dispatch.o src/kernel/dispatch.s -march=rv32i_zicsr -mabi=ilp32 -fPIC -nostdlib -nostartfiles
	riscv32-unknown-elf-gcc -c -g -Isrc/kernel/include -o build/context.o src/kernel/context.c             -march=rv32i_zicsr -mabi=ilp32 -fPIC -nostdlib -nostartfiles

	riscv32-unknown-elf-gcc -c -g -o build/setTrapVector.o src/kernel/setTrapVector.s -march=rv32i_zicsr -mabi=ilp32 -fPIC -nostdlib -nostartfiles
	riscv32-unknown-elf-gcc -c -g -o build/trap_vector.o src/kernel/trap_vector.s -march=rv32i_zicsr -mabi=ilp32 -fPIC -nostdlib -nostartfiles

	riscv32-unknown-elf-gcc -c -g -o build/main.o src/main.c -Isrc/kernel/include -march=rv32i_zicsr -mabi=ilp32 -fPIC -nostdlib -nostartfiles


	riscv32-unknown-elf-gcc -g -T src/link.ld build/start.o build/dispatch.o build/context.o build/timer_handler.o build/trap_vector.o build/setTrapVector.o  build/main.o -o martos -march=rv32i_zicsr -mabi=ilp32 -fPIC -nostdlib -nostartfiles
