#ifndef PRO_LAB4_BASE_H
#define PRO_LAB4_BASE_H
#include <stdio.h>
#include <malloc.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

pthread_t P1;
pthread_t P2;
pthread_t P3;
pthread_t P4;
pthread_t P5;
pthread_t P6;

pthread_barrier_t BCR2;


pthread_cond_t  SIG21 = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutSIG = PTHREAD_MUTEX_INITIALIZER;

pthread_mutex_t MCR1 = PTHREAD_MUTEX_INITIALIZER;
sem_t SCR1;

int flag2 = 0;
int flag5 = 0;

int flagOfEnd = 2;

int int_1;
int int_2;
unsigned  unsigned_1;
unsigned  unsigned_2;
long  long_1;
long  long_2;
unsigned long unsigned_long_1;
unsigned long unsigned_long_2;

int max_numbers_of_buf = 6;
int max_queue_length = 12;

#endif //PRO_LAB4_BASE_H
