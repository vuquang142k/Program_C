#include <stdlib.h>
#include <string.h>
#include "my_functions.h"

char *my_strpbrk(char *str1, char *str2)
{
    int i = 0, j = 0;
    while (str1[i])
    {
        while (str2[j])
        {
            if (str1[i] == str2[j])
                return (char *)&str1[i];
            j++;
        }
        i++;
        j = 0;
    }
    return NULL;
}
size_t my_strspn(char *str1, char *str2)
{
    size_t count = 0;
    int fi;
    for (int i = 0; str1[i]; i++)
    {
        fi = 1;
        for (int j = 0; str2[j]; j++)
            if (str1[i] == str2[j])
                fi = 0;
        if (fi)
            return count;
        count++;
    }
    return count;
}
size_t my_strcspn(char *str1, char *str2)
{
    size_t count = 0;
    int fi;
    for (int i = 0; str1[i]; i++)
    {
        fi = 0;
        for (int j = 0; str2[j]; j++)
            if (str1[i] == str2[j])
                fi = 1;
        if (fi)
            return count;
        count++;
    }
    return count;
}

char *my_strchr(shortstring_t str, int c)
{
    size_t i;
    for (i = 0; str[i]; i++)
    {
        if (str[i] == c)
        {
            return str + i;
        }
    }
    if (str[i] == c)
        return str + i;
    return NULL; 
}
char *my_strrchr(shortstring_t str, int c)
{
    char *p = NULL;
    size_t i;
    for (i = 0; str[i]; i++)
    {
        if (str[i] == c)
        {
            p = str + i;
        }
    }
    if (str[i] == c)
        p = str + i;
    return p;
}