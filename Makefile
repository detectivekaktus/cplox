CC = g++
CFLAGS = -Wall -Wextra -pedantic
SOURCES = src/lox.cpp
TARGETS = build/lox.o

all: build $(TARGETS)
	$(CC) $(CFLAGS) $(TARGETS) -o build/lox

$(TARGETS): $(SOURCES)
	$(CC) $(CFLAGS) -c $< -o $@

build:
	mkdir -p build

clean:
	rm -f build/*

.PHONY: all clean
