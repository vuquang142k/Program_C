#include <stdio.h>
#include <stdlib.h>
#define ROW 10
#define COL 10
#define ERROR -1
#define OK 0
 
int sumdigit(int number)
{
    if (number < 0)
    {
        number *= (-1);
    }
    int sum = 0;
    while (number != 0)
    {
        sum += number % 10;
        number = number / 10;
    }
    return sum;
}
 
int main()
{
    int arr[ROW][COL], res[ROW];
    int n_row, n_col, input, k, res_count = 0;
 
    printf("Input Row and Column: ");
    int rc = scanf("%d %d", &n_row, &n_col);
 
    if (rc == 2 && n_row > 0 && n_row <= ROW && n_col > 0 && n_col <= COL)
    {
        for (int i = 0; i < n_row; i++)
        {
            for (int j = 0; j < n_col; j++)
            {
                if (scanf("%d", &input) == 1)
                {
                    arr[i][j] = input;
                }
                else
                {
                    return ERROR;
                }
            }
        }
    }
    else
    {
        return ERROR;
    }
 
    for (int i = 0; i < n_row; i++)
    {
        k = 2;
        for (int j = 0; j < n_col; j++)
        {
            if (sumdigit(arr[i][j]) % 2 == 1)
            {
                k--;
            }
            if (k == 0)
            {
                break;
            }
        }
        if (k == 0)
        {
            res[res_count++] = 1;
        }
        else
        {
            res[res_count++] = 0;
        }
    }
 
    for (int i = 0; i < n_row;i++)
    {
        if (res[i] == 1)
        {
            for (int l = 0; l < n_col;l++)
                printf("-1 ");
            printf("\n");
        }
        for (int j = 0; j < n_col;j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return OK;
}