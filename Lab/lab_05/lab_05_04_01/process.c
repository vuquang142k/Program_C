#include "process.h"

double average_student(unsigned int *arr, int size)
{
    double sum_stud = 0;

    for (int i = 0; i < size; ++i)
        sum_stud += arr[i];

    sum_stud /= COUNT_MARK;
    return sum_stud;
}
double average_all_students_bin(FILE *const f)
{
    size_t size;
    file_size(f, &size);

    student_r student;
    memset(&student, 0, sizeof(student_r));

    double sum = 0;
    double ave = 0;

    for (size_t i = 0; i < size; ++i)
    {
        get_student_by_pos(f, i, &student);
        sum += average_student(student.marks, COUNT_MARK);
    }

    ave = sum / size;

    return ave;
}
double average_all_students_txt(student_r *students, int len_student)
{
    double sum = 0;

    for (int i = 0; i < len_student; ++i)
    {
        sum += average_student(students[i].marks, COUNT_MARK);
    }

    sum /= len_student;

    return sum;
}
int file_new_del_los(FILE *const f, FILE *const f_copy)
{
    double average_overall = average_all_students_bin(f);

    fseek(f, 0L, SEEK_SET);

    size_t size;
    file_size(f, &size);

    student_r student;
    memset(&student, 0, sizeof(student_r));

    int new_count = 0;
    for (size_t i = 0; i < size; i++)
    {
        get_student_by_pos(f, i, &student);
        if (fabs(average_student(student.marks, COUNT_MARK) - average_overall) < EPS || \
            (average_student(student.marks, COUNT_MARK) - average_overall) >= EPS)
        {
            fwrite(&student, sizeof(student_r), 1, f_copy);
            new_count++;
        }
    }

    return new_count;
}
void arr_new_del_los(student_r *students, int len_student, FILE *const f_in_out)
{
    double average_overall = average_all_students_txt(students, len_student);

    for (int i = 0; i < len_student; i++)
        if (fabs(average_student(students[i].marks, COUNT_MARK) - average_overall) < EPS || \
            (average_student(students[i].marks, COUNT_MARK) - average_overall) >= EPS)
        {
            print_struct_to_file_txt(f_in_out, students[i]);
        }
}
int file_size(FILE *const fsrc, size_t *size)
{
    fseek(fsrc, 0, SEEK_END);

    *size = ftell(fsrc);

    if ((*size <= 0) || (*size < sizeof(student_r)))
        return OPEN_ERROR;

    *size = *size / sizeof(student_r);

    return fseek(fsrc, 0, SEEK_SET);;
}

int checking_file_for_correct(FILE *f)
{
    student_r var_for_check;
    memset(&var_for_check, 0, sizeof(student_r));

    if (f == NULL)
        return OPEN_ERROR;

    size_t size;
    file_size(f, &size);

    if (size <= 0)
        return FILE_EMPTY;

    fseek(f, 0L, SEEK_SET);

    for (size_t i = 0; i < size; i++)
    {
        int read = fread(&var_for_check, sizeof(student_r), 1, f);

        if (read != 1)
            return INVALID_ARG;
    }

    return OK;
}
int from_file_to_array(FILE *const f, student_r student[])
{
    int i = 0;
    while (fscanf(f, "%s %s", student[i].surname, student[i].name) == 2)
    {
        int rc;
        for (int j = 0; j < COUNT_MARK; j++)
        {
            rc = fscanf(f, "%u", &student[i].marks[j]);

            if (rc == 0)
                return INVALID_ARG;
        }

        i++;
    }

    if (i)
        return i;
    else
        return INVALID_ARG;
}
void file_copy_bin(FILE *const f_in_out, FILE *const f_copy)
{
    size_t size;
    file_size(f_copy, &size);

    student_r student;
    memset(&student, 0, sizeof(student_r));

    for (size_t i = 0; i < size; ++i)
    {
        get_student_by_pos(f_copy, i, &student);
        fwrite(&student, sizeof(student_r), 1, f_in_out);
    }
}
void get_student_by_pos(FILE *fsrc, int pos, student_r *er)
{
    pos = pos * sizeof(student_r);
    fseek(fsrc, pos, SEEK_SET);
    fread(er, sizeof(student_r), 1, fsrc);
}
void put_student_by_pos(FILE *fsrc, int pos, student_r er)
{
    pos = pos * sizeof(student_r);
    fseek(fsrc, pos, SEEK_SET);
    fwrite(&er, sizeof(student_r), 1, fsrc);
}
void print_struct_to_file_txt(FILE *const f, student_r s)
{
    fprintf(f, "%s\n", s.surname);
    fprintf(f, "%s\n", s.name);

    for (int j = 0; j < COUNT_MARK; j++)
        fprintf(f, "%d ", s.marks[j]);
    fprintf(f, "\n");
}
void struct_print(student_r s)
{
    printf("%s\n", s.surname);
    printf("%s\n", s.name);

    for (int i = 0; i < COUNT_MARK; i++)
        printf("%u ", s.marks[i]);

    printf("\n");
}

void print_file_bin(FILE *const f)
{
    fseek(f, 0L, SEEK_SET);

    student_r student;
    memset(&student, 0, sizeof(student_r));
    size_t n = 0;
    file_size(f, &n);

    for (size_t i = 0; i < n; i++)
    {
        fread(&student, sizeof(student_r), 1, f);
        struct_print(student);
    }
}
void sort_file_txt(student_r students[], int n)
{
    student_r buf;
    memset(&buf, 0, sizeof(student_r));

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (strcmp(students[i].surname, students[j].surname) > 0)
            {
                buf = students[i];
                students[i] = students[j];
                students[j] = buf;
            }
            else
            {
                if (strcmp(students[i].surname, students[j].surname) == 0)
                {
                    if (strcmp(students[i].name, students[j].name) > 0)
                    {
                        buf = students[i];
                        students[i] = students[j];
                        students[j] = buf;
                    }
                }
            }
        }
    }
}
void sort_file_bin(FILE *const fsrc)
{
    size_t i, j, n = 0;
    student_r student_f, student_s;
    memset(&student_f, 0, sizeof(student_r));
    memset(&student_s, 0, sizeof(student_r));

    file_size(fsrc, &n);

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; ++j)
        {
            get_student_by_pos(fsrc, i, &student_f);
            get_student_by_pos(fsrc, j, &student_s);

            if (strcmp(student_f.surname, student_s.surname) > 0)
            {
                put_student_by_pos(fsrc, i, student_s);
                put_student_by_pos(fsrc, j, student_f);
            }
            else
            {
                if (strcmp(student_f.surname, student_s.surname) == 0)
                {
                    if (strcmp(student_f.name, student_s.name) > 0)
                    {
                        put_student_by_pos(fsrc, i, student_s);
                        put_student_by_pos(fsrc, j, student_f);
                    }
                }
            }
        }
    }
}
int surname_substr_bin(FILE *const f_in, FILE *const f_out, const char *substr)
{
    size_t size;
    student_r student;
    memset(&student, 0, sizeof(student_r));
    file_size(f_in, &size);

    int count_substr = 0;

    for (size_t i = 0; i < size; ++i)
    {
        get_student_by_pos(f_in, i, &student);
        char *check = strstr(student.surname, substr);
        int check_ = check - student.surname;
        if (check_ == 0)
        {
            fwrite(&student, sizeof(student_r), 1, f_out);
            count_substr++;
        }
    }

    return count_substr;
}

int surname_substr_txt(student_r students[], FILE *const f_out, int n, const char *substr)
{
    int count_substr = 0;
    for (int i = 0; i < n; i++)
    {
        if (strncmp(students[i].surname, substr, strlen(substr)) == 0)
        {
            print_struct_to_file_txt(f_out, students[i]);
            count_substr++;
        }
    }

    return count_substr;
}
