#include <stdio.h>
#define N 10

int read(int a[], int *n)
{
    printf("Inpur size of array(intrger) ");
    int fi;
    int rc = scanf("%d", n);
    if (rc == 1)
    {
        fi = 1;
        if ((*n > 0) && (*n <= 10))
        {
            fi = 1;
            int s;
            for (int i = 0; i < *n; i++)
            {
                printf("Element of array ");
                rc = scanf("%d", &s);
                if (rc == 1)
                    a[i] = s;
                else
                {
                    fi = 0;
                    break;
                }
            }
        }
        else
        {
            fi = 0;
        }
    }
    else
    {
        fi = 0;
    }
    return fi;
}

int arr_p(int a[], int n)
{
    int f = 0;
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            f = 1;
            k = k + a[i];
        }
    }
    if (f)
        return k;
    else
        return 1;
}

int main()
{
    int a[N];
    int n;
    int fi = read(a, &n);
    if (fi)
    {
        int k;
        k = arr_p(a, n);
        if (k != 1)
        {
            printf("%d", k);
            return 0;
        }
        else
        {
            printf("Input error");
            return -1;
        }
    }
    else
    {
        printf("Input error");
        return -1;
    }
}

