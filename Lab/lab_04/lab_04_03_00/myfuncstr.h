#ifndef _MYFUNCSTR_H
#define _MYFUNCSTR_H

#define STR_LEN 257
#define MAX_WORD_LEN 17
#define MAX_WORDS 512

typedef char shortstring_t[STR_LEN];
typedef shortstring_t shortstrings_t[100];

int string_split(char *str, char *pword_array[], shortstrings_t word_array, shortstring_t delims);
int clean(shortstrings_t word_array, size_t n);
void word_arr(shortstrings_t word_array, size_t n);
void str_new(shortstring_t new_str, shortstrings_t word_array, size_t n);

#endif