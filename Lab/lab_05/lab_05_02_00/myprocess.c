#include "myprocess.h"

int process(FILE *f, double *ans)
{
    double sum = 0;
    double element;
    int count = 0;
    while (fscanf(f, "%lf", &element) == 1)
    {
        sum += element;
        count++;
    }
    if (count == 0)
        return ERR;
    fseek(f, 0L, SEEK_SET);
    double average = sum / count;
    double min = 99999999999;
    while (fscanf(f, "%lf", &element) == 1)
    {
        if (fabs(element - average) < min)
        {
            *ans = element;
            min = fabs(element - average);
        }
    }
    return 0;
}

