#ifndef _MY_FUNCTIONS_H_
#define _MY_FUNCTIONS_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define STR_LEN 257

typedef char shortstring_t[STR_LEN];

char *my_strpbrk(char *str1, char *str2);
size_t my_strspn(char *str1, char *str2);
size_t my_strcspn(char *str1, char *str2);
char *my_strchr(shortstring_t str, int c);
char *my_strrchr(shortstring_t str, int c);

#endif 