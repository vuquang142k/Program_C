#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    long long m;
    long long a;

    scanf("%lld", &m);
    a = m / 25;
    if (m < 45)
    {
        printf("0");
        return 0;
    }
    if (m - (a - 1) * 25 >= 45)
        printf("%lld", a);
    else
        printf("%lld", a - 1);
    return EXIT_SUCCESS;
}
