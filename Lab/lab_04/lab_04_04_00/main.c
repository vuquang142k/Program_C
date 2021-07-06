#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "mystr.h"

int main(void)
{
    shortstring_t str;
    if (!my_fgets(str, stdin))
        return 1;
    if (isaddress(str))
        printf("YES");
    else
        printf("NO");
    return EXIT_SUCCESS;
}