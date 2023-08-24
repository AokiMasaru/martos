# start.oを一番はじめにリンクすること　.textセクションの先頭に置きたい
OBJS = build/start.o   build/context.o   build/inittsk.o  build/scheduler.o      build/task_manage.o  build/timer_handler.o  build/usermain.o build/dispatch.o  build/kernel.o   build/setTrapVector.o  build/syslib.o  build/task_queue.o   build/trap_vector.o

all:
	rm -rf build/*.o

	riscv32-unknown-elf-gcc -c -g -Isrc/kernel/include -o build/context.o src/kernel/context.c             -march=rv32i_zicsr -mabi=ilp32 -fPIC -nostdlib -nostartfiles
	riscv32-unknown-elf-gcc -c -g -o build/dispatch.o src/kernel/dispatch.s -march=rv32i_zicsr -mabi=ilp32 -fPIC -nostdlib -nostartfiles
	riscv32-unknown-elf-gcc -c -g -Isrc/kernel/include -o build/inittsk.o src/kernel/inittsk.c               -march=rv32i_zicsr -mabi=ilp32 -fPIC -nostdlib -nostartfiles
	riscv32-unknown-elf-gcc -c -g -Isrc/kernel/include -o build/kernel.o src/kernel/kernel.c               -march=rv32i_zicsr -mabi=ilp32 -fPIC -nostdlib -nostartfiles
	riscv32-unknown-elf-gcc -c -g -Isrc/kernel/include -o build/scheduler.o src/kernel/scheduler.c               -march=rv32i_zicsr -mabi=ilp32 -fPIC -nostdlib -nostartfiles
	riscv32-unknown-elf-gcc -c -g -o build/setTrapVector.o src/kernel/setTrapVector.s -march=rv32i_zicsr -mabi=ilp32 -fPIC -nostdlib -nostartfiles
	riscv32-unknown-elf-gcc -c -g -Isrc/kernel/include -o build/syslib.o src/kernel/syslib.c               -march=rv32i_zicsr -mabi=ilp32 -fPIC -nostdlib -nostartfiles
	riscv32-unknown-elf-gcc -c -g -Isrc/kernel/include -o build/task_manage.o src/kernel/task_manage.c               -march=rv32i_zicsr -mabi=ilp32 -fPIC -nostdlib -nostartfiles
	riscv32-unknown-elf-gcc -c -g -Isrc/kernel/include -o build/task_queue.o src/kernel/task_queue.c               -march=rv32i_zicsr -mabi=ilp32 -fPIC -nostdlib -nostartfiles
	riscv32-unknown-elf-gcc -c -g -o build/timer_handler.o src/kernel/timer_handler.s -march=rv32i_zicsr -mabi=ilp32 -fPIC -nostdlib -nostartfiles
	riscv32-unknown-elf-gcc -c -g -o build/trap_vector.o src/kernel/trap_vector.s -march=rv32i_zicsr -mabi=ilp32 -fPIC -nostdlib -nostartfiles
	riscv32-unknown-elf-gcc -c -g -o build/start.o src/start.s -march=rv32i_zicsr -mabi=ilp32 -fPIC -nostdlib -nostartfiles




	riscv32-unknown-elf-gcc -c -g -o build/usermain.o src/usermain.c -Isrc/kernel/include -march=rv32i_zicsr -mabi=ilp32 -fPIC -nostdlib -nostartfiles


	riscv32-unknown-elf-gcc -g -T src/link.ld $(OBJS) -o martos -march=rv32i_zicsr -mabi=ilp32 -fPIC -nostdlib -nostartfiles
