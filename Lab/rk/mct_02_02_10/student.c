#include "student.h"

int file_size(FILE *f, size_t *size)
{
    fseek(f, 0, SEEK_END);

    *size = ftell(f);

    if ((*size <= 0) || (*size < sizeof(student_t)))
        return OPEN_ERROR;

    *size = *size / sizeof(student_t);

    return fseek(f, 0, SEEK_SET);;
}
void get_student_by_pos(FILE *f, int pos, student_t *er)
{
    pos = pos * sizeof(student_t);
    fseek(f, pos, SEEK_SET);
    fread(er, sizeof(student_t), 1, f);
}
void put_student_by_pos(FILE *f, int pos, student_t er)
{
    pos = pos * sizeof(student_t);
    fseek(f, pos, SEEK_SET);
    fwrite(&er, sizeof(student_t), 1, f);
}
int print_student(student_t student)
{
    printf("%s\n", student.name);
    printf("%"PRId32"\n", student.point);
}

int del_student(FILE *f, char *start, char *end)
{
    size_t n;
    int pos = file_size(f, &n);
    if (pos != 0 || n % sizeof(student_t) != 0)
        return ERROR;
    n = n / sizeof(student_t);
    for (size_t i = 0; i < n; i++)
    {
        student_t str1, str2;
        get_student_by_pos(f, i, &str1);
        if (strcmp(str1.name, start) > 0 && strcmp(str1.name, end) < 0)
        {
            for (size_t j = i; j < n - 1; j++)
            {
                get_student_by_pos(f, j + 1, &str2);
                put_student_by_pos(f, j, str2);
            }
        }
    }
    return EXIT_SUCCESS;
}