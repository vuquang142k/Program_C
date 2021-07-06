#ifndef _COMMAND_H
#define _COMMAND_H

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <stdlib.h>

#define OK 0
#define OPEN_ERROR 2
#define EPS 1e-06
#define NOT_ENOUGH_ARG 1
#define WRITE_ERROR 3
#define READ_ERROR 4
#define GET_PUT_ERROR -5

int get_number_by_pos(FILE *fsrc, size_t pos, int *er);
int put_number_by_pos(FILE *fsrc, size_t pos, int num, int *er);
int command_c(FILE *fsrc, char *count_str);
int file_size(FILE *fsrc, size_t *size);
int command_p(FILE *fsrc);
int command_s(FILE *fsrc);

#endif // _COMMAND_H
