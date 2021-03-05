#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double g(double x, double b, double eps, double t, int i)
{
    b = 0.0;
    t = 1.0;
    i = 0;
    while (fabs(t) > eps)
    {
        b += t;
        i += 1;
        t = t * x / i;
    }
    return b;
}

int main(void)
{
    double x, eps;
    double a, b = 0.0;
    double t = 1.0;
    int i = 0;
    double delta, beta;
    int rc = scanf("%lf %lf", &x, &eps);
    if ((rc == 2) && (eps < 1) && (eps > 0))
    {
        a = exp(x);
        b = g(x, b, eps, t, i);
        delta = fabs(a - b);
        beta = fabs(a - b) / a;
        printf("%lf\n", b);
        printf("%lf\n", a);
        printf("%lf\n", delta);
        printf("%lf", beta);
        return EXIT_SUCCESS;
    }
    else
    {
        printf("Input error");
        return -1;
    }
}
