#include <stdio.h>
#include <inttypes.h>
#include <sys/time.h>
#define N 10

int process_1(int a[], int n)
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

int process_2(int *pa, int *pb)
{
    int res = 0;
    for (; pa < pb; pa++)
    {
        int flag = 0;
        int *pa1 = pa;
        for (; pa1 < pb; pa1++)
        {
            if (*pa == *pa1)
                flag++;
        }
        if (flag == 1)
            res++;
    }
    return res;
}

int read_2(int *pa, int *pb)
{
    int fi;
    int rc;
    fi = 1;
    int s;
    for (; pa < pb;)
    {
        printf("Element of array ");
        rc = scanf("%d", &s);
        if (rc == 1)
        {
            *pa = s;
            pa++;
        }
        else
        {
            fi = 0;
            break;
        }
    }
    return fi;
}

int read_1(int a[], int *n)
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

int main()
{
    int a[N];
    int n;
    int kol = -1;
    int fi = read_1(a, &n);
    if (fi)
    {
        int sum = 0;
        for (int i = 0; i< 100000; i++)
        {
            int nb = n;
            int b[nb];
            for(int j = 0; j < 10; j++) {
                b[j] = a[j];
            }
            clock_t start = clock();
            kol = process_1(a, n);
            clock_t end = clock();
            sum += (end - start)/(double)CLOCKS_PER_SEC;
        }  
        double time = sum / 100000;    
        if (kol != -1)
        {
            printf("%lf", time);
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