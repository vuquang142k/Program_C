#include "product.h"

int my_fgets(FILE *f, str s, size_t n)
{
    if(!fgets(s, n + 1, f))
        return 0;
    size_t len = strlen(s);
    if(len == n && s[len - 1] != '\n')
        return 0;
    if(len == 1 && s[len - 1] != '\n')
        return 0;
    if(s[len - 1] == '\n')
        s[len - 1] = 0;
    return 1;
}
int remove_letter(char src[], char delims[], char dst[])
{
    size_t a = strlen(src);
    size_t b = 0;
    for (size_t i = 0; i < a; i++)
    {
        if(strchr(delims, src[i]) != NULL)
            dst[b++] = src[i];
    }
    dst[b] = 0;
    return b;
}
int is_palind(char str[])
{
    size_t n = strlen(str);
    for (size_t i = 0; i < n / 2; i++)
    {
        if(str[i] != str[n - 1 - i])
            return 0;
    }
    return 1;
}