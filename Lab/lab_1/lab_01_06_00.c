#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MIN 1e-6

int check(double xa, double ya, double xb, double yb, double xc, double yc)
{
    if (fabs(((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb)) - ((xc - xb) * (xc - xb) + (yc - yb) * (yc - yb)) - ((xa - xc) * (xa - xc) + (ya - yc) * (ya - yc))) <= MIN || fabs(((xc - xb) * (xc - xb) + (yc - yb) * (yc - yb)) - ((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb)) - ((xa - xc) * (xa - xc) + (ya - yc) * (ya - yc))) <= MIN || fabs(((xa - xc) * (xa - xc) + (ya - yc) * (ya - yc)) - ((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb)) - ((xc - xb) * (xc - xb) + (yc - yb) * (yc - yb))) <= MIN)
        return 1;
    else if (((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb)) > ((xc - xb) * (xc - xb) + (yc - yb) * (yc - yb)) + ((xa - xc) * (xa - xc) + (ya - yc) * (ya - yc)) || ((xc - xb) * (xc - xb) + (yc - yb) * (yc - yb)) > ((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb)) + ((xa - xc) * (xa - xc) + (ya - yc) * (ya - yc)) || ((xa - xc) * (xa - xc) + (ya - yc) * (ya - yc)) > ((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb)) + ((xc - xb) * (xc - xb) + (yc - yb) * (yc - yb)))    
        return 2;
    else
        return 0;
}

int main(void)
{
    double xa, ya, xb, yb, xc, yc;
    int rc = scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &xb, &yb, &xc, &yc);
    if (rc == 6 && fabs((xa - xb) * (ya - yc) - (ya - yb) * (xa - xc)) > MIN)
        printf("%d", check(xa, ya, xb, yb, xc, yc));
    else
    {
        printf("Input error");
        return -1;
    }
    return EXIT_SUCCESS;
}
