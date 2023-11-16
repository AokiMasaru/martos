
target = martos
# start.oを一番はじめにリンクすること　.textセクションの先頭に置きたい
OBJS = 	build/start.o   \
		build/context.o \
		build/inittsk.o \
		build/scheduler.o \
		build/task_manage.o build/task_sync.o  build/timer_handler.o  build/usermain.o build/dispatch.o  build/kernel.o   build/setTrapVector.o  build/syslib.o  build/task_queue.o   build/trap_vector.o build/systimer.o

all: bin hex

bin: $(target)
	riscv32-unknown-elf-gcc -c -g -ggdb -Isrc/kernel/include -o build/context.o src/kernel/context.c             -march=rv32i_zicsr -mabi=ilp32 -fPIC -nostdlib -nostartfiles
	riscv32-unknown-elf-gcc -c -g -ggdb                      -o build/dispatch.o src/kernel/dispatch.s           -march=rv32i_zicsr -mabi=ilp32 -fPIC -nostdlib -nostartfiles
	riscv32-unknown-elf-gcc -c -g -ggdb -Isrc/kernel/include -o build/inittsk.o src/kernel/inittsk.c             -march=rv32i_zicsr -mabi=ilp32 -fPIC -nostdlib -nostartfiles
	riscv32-unknown-elf-gcc -c -g -ggdb -Isrc/kernel/include -o build/kernel.o src/kernel/kernel.c               -march=rv32i_zicsr -mabi=ilp32 -fPIC -nostdlib -nostartfiles
	riscv32-unknown-elf-gcc -c -g -ggdb -Isrc/kernel/include -o build/scheduler.o src/kernel/scheduler.c         -march=rv32i_zicsr -mabi=ilp32 -fPIC -nostdlib -nostartfiles
	riscv32-unknown-elf-gcc -c -g -ggdb                      -o build/setTrapVector.o src/kernel/setTrapVector.s -march=rv32i_zicsr -mabi=ilp32 -fPIC -nostdlib -nostartfiles
	riscv32-unknown-elf-gcc -c -g -ggdb -Isrc/kernel/include -o build/systimer.o src/kernel/systimer.c           -march=rv32i_zicsr -mabi=ilp32 -fPIC -nostdlib -nostartfiles
	riscv32-unknown-elf-gcc -c -g -ggdb -Isrc/kernel/include -o build/syslib.o src/kernel/syslib.c               -march=rv32i_zicsr -mabi=ilp32 -fPIC -nostdlib -nostartfiles
	riscv32-unknown-elf-gcc -c -g -ggdb -Isrc/kernel/include -o build/task_manage.o src/kernel/task_manage.c     -march=rv32i_zicsr -mabi=ilp32 -fPIC -nostdlib -nostartfiles
	riscv32-unknown-elf-gcc -c -g -ggdb -Isrc/kernel/include -o build/task_queue.o src/kernel/task_queue.c       -march=rv32i_zicsr -mabi=ilp32 -fPIC -nostdlib -nostartfiles
	riscv32-unknown-elf-gcc -c -g -ggdb -Isrc/kernel/include -o build/task_sync.o src/kernel/task_sync.c         -march=rv32i_zicsr -mabi=ilp32 -fPIC -nostdlib -nostartfiles
	riscv32-unknown-elf-gcc -c -g -ggdb -o build/timer_handler.o src/kernel/timer_handler.s                      -march=rv32i_zicsr -mabi=ilp32 -fPIC -nostdlib -nostartfiles
	riscv32-unknown-elf-gcc -c -g -ggdb -o build/trap_vector.o src/kernel/trap_vector.s                          -march=rv32i_zicsr -mabi=ilp32 -fPIC -nostdlib -nostartfiles
	riscv32-unknown-elf-gcc -c -g -ggdb -o build/start.o src/start.s                                             -march=rv32i_zicsr -mabi=ilp32 -fPIC -nostdlib -nostartfiles


	riscv32-unknown-elf-gcc -c -g -ggdb -o build/usermain.o src/usermain.c -Isrc/kernel/include -march=rv32i_zicsr -mabi=ilp32 -fPIC -nostdlib -nostartfiles

	riscv32-unknown-elf-gcc -g -ggdb -T src/link.ld $(OBJS) -o $(target) -march=rv32i_zicsr -mabi=ilp32 -fPIC -nostdlib -nostartfiles

hex:
# -S デバッグ情報のストリップ
	riscv32-unknown-elf-objcopy -S --only-section=.text   -O binary $(target) $(target).rom.bin
	riscv32-unknown-elf-objcopy -S --remove-section=.text -O binary $(target) $(target).ram.bin
	riscv32-unknown-elf-objdump -l -S --disassemble-zeroes --debugging --section=.text --section=.text.startup --section=.text.init --section=.data $(target) > $(target).dump
	hexdump -v -e '1/4 "%08x" "\n"' $(target).rom.bin > $(target).rom.hex
	hexdump -v -e '1/4 "%08x" "\n"' $(target).ram.bin > $(target).ram.hex
	echo "memory_initialization_radix=16;\nmemory_initialization_vector=" > $(target).rom.coe;hexdump -v -e '1/4 "%08x" ",\n"' $(target).rom.bin >> $(target).rom.coe ; echo "00000000" >> $(target).rom.coe;
	echo "memory_initialization_radix=16;\nmemory_initialization_vector=" > $(target).ram.coe;hexdump -v -e '1/4 "%08x" ",\n"' $(target).ram.bin >> $(target).ram.coe ; echo "00000000" >> $(target).ram.coe;

clean:
	rm -rf build/*
	rm -rf *.hex *.coe *.bin
