#ifndef _STUDENT_H_
#define _STUDENT_H_

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<string.h>

#define MAX_NAME_LEN 126

#define OPEN_ERROR 1
#define ERROR 2

typedef struct{
    char name[MAX_NAME_LEN];
    int32_t point;
} student_t;

int file_size(FILE *f, size_t *size);
void get_student_by_pos(FILE *f, int pos, student_t *er);
void put_student_by_pos(FILE *f, int pos, student_t er);
int print_student(student_t student);
int del_student(FILE *f, char *start, char *end);

#endif
