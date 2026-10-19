CC = avr-gcc
C_FLAGS = -Wall -Wextra -Werror
CPP_FLAGS = -I. -Imylib/inc -DF_CPU=16000000UL

SRC = main.c $(wildcard mylib/src/*.c)
OBJ_DIR = obj/
OBJ = $(patsubst mylib/src/%.c,$(OBJ_DIR)%.o,$(filter %.c,$(SRC)))

BIN_DIR = bin/
BIN = $(BIN_DIR)main.bin
HEX = $(BIN_DIR)main.hex
ASM = $(BIN_DIR)main.s

MCU = atmega328p
BOOT_LOAD = arduino
PORT = /dev/ttyUSB0

all: hex

hex: $(HEX)

$(OBJ_DIR)%.o: mylib/src/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) -mmcu=$(MCU) $(C_FLAGS) $(CPP_FLAGS) -Os -c $< -o $@

$(OBJ_DIR)main.o: main.c
	mkdir -p $(OBJ_DIR)
	$(CC) -mmcu=$(MCU) $(C_FLAGS) $(CPP_FLAGS) -Os -c $< -o $@

$(BIN): $(OBJ)
	mkdir -p $(BIN_DIR)
	$(CC) -mmcu=$(MCU) $(C_FLAGS) $(CPP_FLAGS) -Os -o $@ $(OBJ)

$(HEX): $(BIN)
	avr-objcopy -O ihex $(BIN) $(HEX)

flash: $(HEX)
	avrdude -p $(MCU) -c $(BOOT_LOAD) -P $(PORT) -U flash:w:$(HEX)

asm: $(ASM)

$(ASM): main.c
	mkdir -p $(BIN_DIR)
	$(CC) -mmcu=$(MCU) $(C_FLAGS) $(CPP_FLAGS) -Os -S main.c -o $(ASM)

screen:
	screen $(PORT) 115200

clean:
	rm -rf $(BIN_DIR) $(OBJ_DIR)