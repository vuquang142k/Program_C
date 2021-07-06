#include<stdio.h>
#include<stdlib.h>
#define N 10
#define NMAX 512

int input_matrix(int a[NMAX][NMAX], size_t r, size_t c)
{
    for (size_t i = 0; i < r; ++i)
        for (size_t j = 0; j < c; ++j)
            if (scanf("%d", &a[i][j]) != 1)
                return EXIT_FAILURE;     
    return EXIT_SUCCESS;
}

void make_list(int a[NMAX][NMAX], size_t r, size_t c, int *b)
{
    for (int j = 0; j < c; j++)
    {
        int flag = 1;
        for (int i = 0; i < r - 1; i++)
        {
            if (a[i][j] <= a[i + 1][j])
            {
                flag = 0;
                break;
            }
        }
        if (r == 1) 
            flag = 0;
        b[j] = flag;
    }
}

void print(int b[NMAX], size_t r)
{
    for (size_t i = 0; i < r; ++i)
        printf("%d ", b[i]);
}

int main(void)
{
    size_t n, m;
    int a[NMAX][NMAX];
    int b[NMAX];
    if (scanf("%zu", &n) != 1 || n < 1 || n > N)
    {
        printf("Input error");
        return -1;
    }
    if (scanf("%zu", &m) != 1 || m < 1 || m > N)
    {
        printf("Input error");
        return -1;
    }
    if (input_matrix(a, n, m))
    {
        printf("Input error");
        return -1;
    }
    make_list(a, n, m, b);
    print(b, m);
    return EXIT_SUCCESS;
}