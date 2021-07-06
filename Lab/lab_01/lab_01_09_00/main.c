#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MIN 1e-6

double calc(double x, int i, double g)
{
    x = 0.0;
    i = 0;
    g = 0.0;
    while (x >= -MIN)
    {
        scanf("%lf", &x);
        if (x < -MIN)
            break;
        i += 1;
        g += x / i;
    }
    return g;    
}

int main()
{
    double x = 0.0;
    int i = 0;
    double g = 0.0;
    printf("%lf", sqrt(calc(x, i, g)));
    return EXIT_SUCCESS;
}
