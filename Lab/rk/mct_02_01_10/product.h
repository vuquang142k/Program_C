#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 65

typedef char str[MAX_STR];

int my_fgets(FILE *f, str s, size_t n);
int remove_letter(char src[], char delims[], char dst[]);
int is_palind(char str[]);

#endif