CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude
SRC = src/main.c src/input.c src/parser.c src/process.c src/builtin.c src/signals.c src/pipes.c
TARGET = bin/cpv

all: $(TARGET)

$(TARGET): $(SRC)
	mkdir -p bin
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf bin/*


asan: CFLAGS += -fsanitize=address -fno-omit-frame-pointer
asan: $(SRC)
	mkdir -p bin
	$(CC) $(CFLAGS) $(SRC) -o bin/cpv-asan
