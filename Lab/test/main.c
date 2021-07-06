#include <stdio.h>
#define ERR_INPUT 1
#define ERR_LOGIC 2

int read_n_m(int *n, int *m)
{
    setbuf(stdout, NULL);
    printf("Input (integer) N and M: ");
    int rc = scanf("%d%d", n, m);
    if (rc == 2)
    {
        if ((*n > 0) && (*n < 11) && (*m > 0) && (*m < 11))
            return 0;
        else
            return ERR_LOGIC;
    }
    else
        return ERR_INPUT;
}
int read_matrix(int *n, int *m, int a[10][10])
{
    for (int i = 0; i < *n; i++)
        for (int j = 0; j < *m; j++)
        {
            int rc = scanf("%d", &a[i][j]);
            if (rc != 1)
                return ERR_INPUT;
        }
    return 0;
}
void chek_matrix(int *n, int *m, int a[10][10], int b[10])
{
    for (int i = 0; i < *n; i++)
    {
        int p = 0;
        for (int j = 0; j < *m; j++)
        {
            if (a[i][j] == a[i][*m - j - 1])
                p++;
        }
        if (p == *m)
            b[i] = 1;
        else
            b[i] = 0;
    }
}
void write_arr(int b[10], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", b[i]);
    }
}
void write_matrix(int a[10][10], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    printf("\n");
}

int main()
{
    
    return 0;
}