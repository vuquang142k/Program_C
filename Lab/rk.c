#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <time.h>
#include <string.h>

#define STR_LEN 257
#define MAX_WORD_LEN 17
#define MAX_WORDS 512

typedef char shortstring_t[STR_LEN];
typedef shortstring_t shortstrings_t[100];

size_t split(shortstring_t str, shortstrings_t a, shortstring_t delims)
{
    size_t i = 0, j = 0, k = 0;
    a[0][0] = 0;
    while (str[k])
    {
        if (!(strchr(delims, str[k]) && j < MAX_WORD_LEN))
            a[i][j++] = str[k];
        else if (j >= MAX_WORD_LEN)
            return 0;
        else if (j > 0)
        {
            a[i++][j] = 0;
            j = 0;
        }
        k++;
    }
    if (j > 0)
    {
        a[i][j] = 0;
        return i + 1;
    }
    return i;
}

char *my_fgets(shortstring_t str, FILE *f)
{
    char buf[STR_LEN + 1];
    if (!fgets(buf, STR_LEN + 1, f))
        return NULL;
    if ((strlen(buf) >= STR_LEN) && buf[STR_LEN - 1] != '\n')
        return NULL;
    char *pos = strrchr(buf, '\n');
    if (pos)
        pos = "\0";
    strcpy(str, buf);
    return str;
}

int main(void)
{
    shortstrings_t ans;
    shortstring_t str;
    shortstring_t delims = " ,;:-.!?\n";
    if (!my_fgets(str, stdin))
        return 1;
    size_t n = split(str, ans, delims);
    if (n == 0)
    {
        printf("Input error");
        return 1;
    }
    for(int i = n - 1; i >= 0; i--)
    {
        for(int j = strlen(ans[i]) - 1; j >= 0; j--)
        {
            printf("%c", ans[i][j]);
        }
        printf(" ");
    }
    return 0;
}

