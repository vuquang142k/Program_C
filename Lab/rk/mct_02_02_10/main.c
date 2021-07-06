#include "student.h"

int main(int argc, char * argv[])
{
    FILE *f;
    char start[] = "Ivanov";
    char end[] = "Pertov";
    if (argc == 3 && !strcmp(argv[1], "wb"))
    {
        f = fopen(argv[2], "ab");
        if (f == NULL)
        {
            printf("Input error");
            return EXIT_FAILURE;
        }
        fseek(f, 0, SEEK_END);
        size_t len = ftell(f) / sizeof(student_t);
        student_t tmp;
        scanf("%s", tmp.name);
        scanf("%"SCNd32, &tmp.point);
        put_student_by_pos(f, len, tmp);
        fclose(f);
    }
    else if (argc == 3 && !strcmp(argv[1], "rb"))
    {
        f = fopen(argv[2], "r+b");
        if (f == NULL)
        {
            printf("Input error");
            fclose(f);
            return EXIT_FAILURE;
        }
        fseek(f, 0, SEEK_END);
        size_t len = ftell(f) / sizeof(student_t);
        student_t tmp;
        for (size_t i = 0; i < len; ++i)
        {
            get_student_by_pos(f, i, &tmp);
            print_student(tmp);
        }
        fclose(f);
    }
    else if(argc == 2)
    {
        f = fopen(argv[1], "r+b");
        if (!f)
        {
            printf("Input error");
            fclose(f);
            return EXIT_FAILURE;
        }
        int rc = del_student(f, start, end);
        fclose(f);
        return rc;
    }
    else
    {
        printf("Input error");
        fclose(f);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;

}