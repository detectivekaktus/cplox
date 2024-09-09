CC = g++
CFLAGS = -Wall -Wextra -pedantic
SOURCES = src/lox.cpp src/lexer/lexer.cpp src/utils/utils.cpp src/main.cpp
TARGETS = build/lox.o build/lexer.o build/utils.o build/main.o

all: build $(TARGETS)
	$(CC) $(CFLAGS) $(TARGETS) -o build/lox

$(TARGETS): $(SOURCES)
	$(CC) $(CFLAGS) -c $< -o $@

build:
	mkdir -p build

clean:
	rm -f build/*

.PHONY: all clean
