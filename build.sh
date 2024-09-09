#!/usr/bin/env bash

CC=g++
CFLAGS="-Wall -Wextra -pedantic -std=c++17"
SRCS=("src/main.cpp" "src/lox.cpp" "src/lexer/lexer.cpp" "src/utils/utils.cpp")

for file in "${SRCS[@]}"; do
  obj=$(basename "${file%.cpp}.o")
  $CC $CFLAGS -c "$file" -o "bin/$obj"
done

$CC $CFLAGS -o bin/lox bin/*.o
