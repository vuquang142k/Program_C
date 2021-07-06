#include<stdio.h>
#include<stdlib.h>
#include "my_functions.h"

int main(void)
{
    printf("Test for strpbrk: ");
    if (strpbrk("abcxasd", "abc") == my_strpbrk("abcxasd", "abc"))
        printf("TEST PASSED\n");
    printf("Test for strspn: ");
    if (strspn("abcxasd", "abc") == my_strspn("abcxasd", "abc"))
        printf("TEST PASSED\n");
    printf("Test for strcspn: ");
    if (strcspn("abcxasd", "abc") == my_strcspn("abcxasd", "abc"))
        printf("TEST PASSED\n");
    printf("Test for strchr: ");
    if (strchr("abcxasd", 98) == my_strchr("abcxasd", 98))
        printf("TEST PASSED\n");
    printf("Test for strrchr: ");
    if (strrchr("abcxasd", 98) == my_strrchr("abcxasd", 98))
        printf("TEST PASSED\n");
    return EXIT_SUCCESS;
}