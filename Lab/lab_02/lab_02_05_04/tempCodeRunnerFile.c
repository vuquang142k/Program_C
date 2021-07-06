int read(int *pa, int *pb)
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