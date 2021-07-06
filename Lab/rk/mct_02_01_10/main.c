#include "product.h"

int main(int argc, char **argv)
{
    str s, dst;
    FILE *f;
    if(argc != 3)
        return EXIT_FAILURE;
    f = fopen(argv[1], "r");
    if(f == NULL)
        return EXIT_FAILURE;
    while (my_fgets(f, s, MAX_STR))
    {
        size_t len = remove_letter(s, argv[2], dst);
        if(len != 0 && is_palind(dst))
            printf("%s\n", s);
    }
    if(!feof(f))
    {
        fclose(f);
        return EXIT_FAILURE;
    }
    fclose(f);
    return EXIT_SUCCESS;
}