#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void)
{
    double a, b;
    double h;
    double d;
    double p;
    scanf("%lf %lf", &a, &b);
    scanf("%lf", &h);
    d = sqrt(h * h + (b - a) * (b - a) / 4);
    p = 2 * d + a + b;
    printf("%lf", p);
    return EXIT_SUCCESS;
}
