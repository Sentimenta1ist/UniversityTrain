// Created by sentimental on 4/14/19.

#include <malloc.h>
#include <stdlib.h>
#include "common.h"



int myGetch(void)   // stackoverflow :)
{
    int c = 0;
    struct termios org_opts, new_opts;
    tcgetattr(STDIN_FILENO, &org_opts);
    memcpy(&new_opts, &org_opts, sizeof(new_opts));
    new_opts.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ICRNL);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_opts);
    c = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &org_opts);
    return (c);
}

void clear()
{
    printf("\033[H\033[J"); // очищення консолі
}

int *vector;
int *vector_of_sum;
int ***arr;


void memory_vector(void)
{
    vector = (int *) malloc(N * sizeof(int *));  // динамічне виділення пам'яті для вектора
}

void memory_vector_of_sum(void)
{
    vector_of_sum = (int *) malloc(N * sizeof(int *)); // динамічне виділення пам'яті для вектора сум
}


void memory_arr(void)
{
    arr = (int ***) malloc(P * sizeof(int **));
    for (int k = 0; k < P; k++)
    {
        arr[k] = (int **) malloc(M * sizeof(int *));  // динамічне виділення пам'яті для втривімрного масиву
        for (int i = 0; i < M; i++)
            arr[k][i] = (int *) malloc(N * sizeof(int));
    }
}

void free_vector_of_sum(void)
{
    free(vector_of_sum);  //очищення вектору сум
}

void free_vector(void)
{
    free(vector); //очищення вектору
}

void free_arr(void)
{
    for (int k = 0; k < P; k++)
    {
        for (int i = 0; i < M; i++)   // очищеггя тривімрного масиву
            free(arr[k][i]);
        free(arr[k]);
    }
    free(arr);
}

void fill_vector_of_sum(void)
{
    for (int i = 0; i < N; i++){ //заповнення вектору сум
        vector_of_sum[i] = 0;
    }
}

void fill_vector(int a) //заповнення вектору трьома способами
{
    switch (a)
    {
        case 0: // ordered
        {
            for (int i = 0; i < N; i++)
            {
                vector[i] = i;
            }
            break;
        }
        case 1: // randomed
        {
            for (int i = 0; i < N; i++)
            {
                vector[i] = rand() % (N);
            }
            break;
        }
        case 2: // backordered
        {
            for (int i = 0; i < N ; i++)
            {
                vector[i] = N - 1 - i;
            }
            break;
        }
        default:
            break;
    }
}


void fill_arr(int a) //заповнення масиву трьома способами
{
    switch (a)
    {
        case 0:  //ordered
        {
            int number = 0;
            for (int k = 0; k < P; k++)
            {
                for (int i = 0; i < M; i++)
                {
                    for (int j = 0; j < N; j++)
                    {
                        arr[k][i][j] = number++;
                    }
                }
            }
            break;
        }
        case 1: //randomed
        {
            for (int k = 0; k < P; k++)
            {
                for (int i = 0; i < M; i++)
                {
                    for (int j = 0; j < N; j++)
                    {
                        arr[k][i][j] = rand() % (P*M*N);
                    }
                }
            }
            break;
        }
        case 2:  //backordered
        {
            int number = P * M * N ;
            for (int k = 0; k < P; k++)
            {
                for (int i = 0; i < M; i++)
                {
                    for (int j = 0; j < N; j++)
                    {
                        arr[k][i][j] = number--;
                    }
                }
            }

            break;
        }

        default:
            break;
    }

}

void output_arr(void)   //вивід масиву
{
    for (int k = 0; k < P; k++)
    {
        printf("Slice #%u:\n", k);
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                printf("%2u%s", arr[k][i][j], j == N - 1 ? "\n" : ", ");
            }

        }
        putchar('\n');
    }
}

void output_vector(void)   // вивід вектору
{
    for (int i = 0; i < N; i++)
        printf("%u%c", vector[i], i == N - 1 ? '\n' : ',');
}
