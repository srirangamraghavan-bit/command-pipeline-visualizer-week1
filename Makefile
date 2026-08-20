CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude

SRC = src/main.c src/input.c
TARGET = bin/cpv

all: $(TARGET)

$(TARGET): $(SRC)
	mkdir -p bin
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf bin/*
