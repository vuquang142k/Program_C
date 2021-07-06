#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myfuncstr.h"

int string_split(char *str, char *pword_array[], shortstrings_t word_array, shortstring_t delims)
{
    char *pword = strtok(str, delims);
    int i = 0, j;
    while (pword)
    {
        pword_array[i++] = pword;
        pword = strtok(NULL, delims);
        int n = strlen(pword_array[i - 1]);
        for (j = 0; j < n; j++)
            word_array[i - 1][j] = pword_array[i - 1][j];
        word_array[i - 1][j] = '\0';
        if (strlen(word_array[i - 1]) > MAX_WORD_LEN)
            return 0;
    }
    return i;
}
int clean(shortstrings_t word_array, size_t n)
{
    for (int i = 0; i < (n - 1); i++)
        if ((strcmp(word_array[i], word_array[n - 1]) == 0))
        {
            for (int k = i; k < (n - 1); k++)
            {
                int m = MAX_WORD_LEN;
                if (strlen(word_array[k]) > strlen(word_array[k + 1]))
                    m = strlen(word_array[k]);
                else
                    m = strlen(word_array[k + 1]);
                for (int l = 0; l < m; l++)
                {
                    char buf = word_array[k][l];
                    word_array[k][l] = word_array[k + 1][l];
                    word_array[k + 1][l] = buf;
                }
            }
            n--;
            i--;
        }
    return --n;
}
void word_arr(shortstrings_t word_array, size_t n)
{
    for (int i = 0; i < n; i++)
    {
        int col = 0;
        int n = strlen(word_array[i]);
        char *p = word_array[i];
        word_array[i][col++] = word_array[i][0];
        for (int j = 1; j < n; j++)
            if (p[j] != p[0])
                word_array[i][col++] = p[j];
        word_array[i][col] = '\0';
    }
}
void str_new(shortstring_t new_str, shortstrings_t word_array, size_t n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        strcat(new_str, word_array[i]);
        if (i != 0)
            strcat(new_str, " ");
    }
}

