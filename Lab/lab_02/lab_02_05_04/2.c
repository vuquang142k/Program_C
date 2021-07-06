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

int found(int a[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i ++)
    {
        int flag = 0;
        for (int j = i; j < n; j ++)
        {
            if (a[j] == a[j])
            {
                flag ++;
            }
        }
        if (flag == 1)
        {
            res ++;
        }
    }
    return res;
}

int main()
{
    int a[N];
    int n;
    int kol = -1;
    int fi = read(a, &n);
    if (fi)
    {
        kol = found(a, n);
        if (kol != -1)
        {
            printf("Number of different elements %d", kol);
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