CC = gcc
CFLAGS = -Wall -Wextra -g -std=c11

SRC = src/my_string.c
TEST = tests/test_main.c
OBJ = $(SRC:.c=.o)
TARGET = test_program.exe

all: $(TARGET)

$(TARGET): $(OBJ) $(TEST)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(TEST)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /Q src\*.o $(TARGET) 2>nul

run: $(TARGET)
	.\$(TARGET)

.PHONY: all clean run