#!/bin/bash
gcc main.c -Wvla -Werror -Wpedantic -Wextra -Wvla -c
gcc product.c -Wvla -Werror -Wpedantic -Wextra -Wvla -c
gcc -o app.exe main.c product.o