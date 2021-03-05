#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    unsigned long a;
    int n;
    int r = scanf("%lu %d", &a, &n);
    if (n >= 0 && n <= 31 && r == 2)
    {
        printf("Result: ");
        for (int x = n - 1; x > -1; x--)
            printf("%d", (a >> x) & 1);
        for (int x = 31; x >= n; x--)
            printf("%d", (a >> x) & 1);
    }
    else
    {
        printf("Error: Input error");
        return -1;
    }
    return EXIT_SUCCESS;
}

