#!/bin/bash
gcc main.c -Wvla -Werror -Wpedantic -Wextra -Wvla -c
gcc student.c -Wvla -Werror -Wpedantic -Wextra -Wvla -c
gcc -o app.exe main.c student.o --coverage