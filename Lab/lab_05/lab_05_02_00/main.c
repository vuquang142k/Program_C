#include "myprocess.h"

int main(int argc, char **argv)
{
    FILE *f;
    double ans;
    f = fopen(argv[1], "r");
    int result = process(f, &ans);
    if (argc != 2)
    {
        printf("Input Error");
        fclose(f);
        return result = ERR;
    }
    if (f == NULL)
    {
        printf("Input Error");
        fclose(f);
        return result = ERR;
    }
    if (result == 0)
    {
        printf("%lf", ans);
        fclose(f);
        return EXIT_SUCCESS;
    }
    printf("Input Error");
    fclose(f);
    return result;
}