#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myfuncstr.h"

#define OK 0
#define ERRORLOGIC 1
#define ERRORINPUT 2

int main()
{
    shortstring_t str;
    shortstring_t delims = " ;,:-.!?\n";
    char *pword_array[MAX_WORDS];
    shortstrings_t word_array = { 0 };
    printf("Input string: ");
    char *p = fgets(str, STR_LEN, stdin);
    if ((p == NULL) || (str[strlen(str) - 1] != '\n'))
    {
        printf("Input error");
        return ERRORINPUT;
    }
    else
    {
        int len_word_array = string_split(str, pword_array, word_array, delims);
        if (len_word_array == 0)
        {
            printf("Input error");
            return ERRORINPUT;
        }
        else
        {
            len_word_array = clean(word_array, len_word_array);
            word_arr(word_array, len_word_array);
            shortstring_t new_str = { 0 };
            str_new(new_str, word_array, len_word_array);
            if (strlen(new_str) != 0)
            {
                printf("Result: %s", new_str);
                return OK;
            }
            else
            {
                printf("Invalid input");
                return ERRORLOGIC;
            }
        }
    }
}