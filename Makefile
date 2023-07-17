all:
	riscv32-unknown-elf-gcc -c -g -o build/start.o src/start.s -march=rv32i_zicsr -mabi=ilp32 -fPIC -nostdlib -nostartfiles

	riscv32-unknown-elf-gcc -c -g -o build/setTrapVector.o src/kernel/setTrapVector.s -march=rv32i_zicsr -mabi=ilp32 -fPIC -nostdlib -nostartfiles
	riscv32-unknown-elf-gcc -c -g -o build/trap_vector.o src/kernel/trap_vector.s -march=rv32i_zicsr -mabi=ilp32 -fPIC -nostdlib -nostartfiles

	riscv32-unknown-elf-gcc -c -g -o build/main.o src/main.c -march=rv32i_zicsr -mabi=ilp32 -fPIC -nostdlib -nostartfiles


	riscv32-unknown-elf-gcc -g -T src/link.ld build/trap_vector.o build/setTrapVector.o build/start.o build/main.o -o martos -march=rv32i_zicsr -mabi=ilp32 -fPIC -nostdlib -nostartfiles
