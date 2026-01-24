CC=arm-none-eabi-gcc
CFLAGS=-mcpu=cortex-m3 -mthumb -nostdlib -Wall
LDFLAGS=-T linker.ld

all: main.elf

main.elf: startup.s main.c
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

clean:
	rm -f *.elf
