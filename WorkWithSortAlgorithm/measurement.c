// Created by sentimental on 4/14/19.
#include "measurement.h"
#include "array_sort.h"
#include "vector_sort.h"
#include <stdio.h>



clock_t Res[measurements_number];

void fill_res_select(void)   //створення масиву результатів для тривімроного сортування вибору
{
    for(int i = 0; i < measurements_number; i++)
    {
        Res[i] = sort_selection_arr();
    }
}

void fill_res_select4(void)  //створення масиву результатів для тривімроного сортування вибору 4
{
    for(int i = 0; i < measurements_number; i++)
    {
        Res[i] = sort_selection_4_arr();
    }
}

void fill_res_select_vector(void)  //створення масиву результатів для вектора. сортування вибору
{
    for(int i = 0; i < measurements_number; i++)
    {
        Res[i] = vector_select();
    }
}

void fill_res_select4_vector(void)  //створення масиву результатів для вектора. сортування вибору 4
{
    for(int i = 0; i < measurements_number; i++)
    {
        Res[i] = vector_select4();
    }
}

void clear_res(void)   // очищення масиву результатів
{
    for(int i = 0;i < measurements_number; i++)
    {
        Res[i] = 0;
    }
}

float MeasurementProcessing()
{
    int Sum;
    float AverageValue;
    clock_t buf;
    int L = rejected_number, R = measurements_number - 1;
    int k = rejected_number;
    for (int j=0; j < min_max_number; j++) {
        for (int i = L; i < R; i++)	{
            if (Res[i] > Res[i + 1]) {
                buf = Res[i];
                Res[i] = Res[i + 1];
                Res[i + 1] = buf;
                k = i;
            }
        }
        R = k;
        for (int i = R - 1; i >= L; i--) {
            if (Res[i] > Res[i + 1]) {
                buf = Res[i];
                Res[i] = Res[i + 1];
                Res[i + 1] = buf;
                k = i;
            }
        }
        L = k + 1;
    }
    Sum=0;
    for (int i = rejected_number + min_max_number; i < measurements_number - min_max_number; i++)
        Sum = Sum + Res[i];
    AverageValue = (float)Sum/(float)(measurements_number - 2*min_max_number - rejected_number);
    return AverageValue;

}

clock_t sort_quick_arr()   //заповнення масиву результатів для тривімрного
{
    clear_res();
    clock_t time_start, time_stop;
        for (int i_res = 0; i_res < measurements_number; i_res++)
        {
            memory_vector_of_sum();
            fill_vector_of_sum();
            time_start = clock();
            for (int slice = 0; slice < P; slice++)
            {
                for (int j_sum = 0; j_sum < N; j_sum++)
                {
                    for (int i_sum = 0; i_sum < M; i_sum++)
                    {
                        vector_of_sum[j_sum] += arr[slice][i_sum][j_sum];
                    }
                }
                QuickSort(0, N - 1, slice);
            }
            time_stop = clock();
            Res[i_res] = time_stop - time_start;
        }
}

clock_t sort_quick_vector(int order)   //заповнення масиву результатів для тривімрного
{
    clear_res();
    clock_t time_start, time_stop;
    for (int i_res = 0; i_res < measurements_number; i_res++)
    {
        fill_vector(order);
        time_start = clock();
        QuickSort_v(0, N - 1);
        time_stop = clock();

        Res[i_res] = time_stop - time_start;
    }
}

