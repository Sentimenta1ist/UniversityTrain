// Created by sentimental on 4/14/19.

#ifndef MYCOURSE_COMMON_H
#define MYCOURSE_COMMON_H

#include "stdio.h"
#include <string.h>
#include <unistd.h>
#include <termios.h>

#define P 3
#define N 10
#define M 15



void clear(void);
int myGetch(void);

extern int *vector;
extern int *vector_of_sum;
extern int ***arr;

void memory_vector_of_sum(void);
void memory_vector(void);
void memory_arr(void);

void free_vector_of_sum(void);
void free_vector(void);
void free_arr(void);

void fill_vector_of_sum(void);
void fill_vector(int a);
void fill_arr(int a);

void output_arr(void);
void output_vector(void);


#endif //MYCOURSE_COMMON_H
