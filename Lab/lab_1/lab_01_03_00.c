#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    double h, t;
    double m;
    double mnor;
    double d;

    scanf("%lf %lf", &h, &t);
    scanf("%lf", &m);

    mnor = h * t / 240;
    d = m / (h * h * pow(10, -4));
    
    printf("%lf\n", mnor);
    printf("%lf", d);

    return EXIT_SUCCESS;
}
