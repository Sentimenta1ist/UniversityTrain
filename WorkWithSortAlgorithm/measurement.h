// Created by sentimental on 4/14/19.


#ifndef MYCOURSE_MEASUREMENT_H
#define MYCOURSE_MEASUREMENT_H

#include <time.h>

#define measurements_number 28    // Загальна кількість вимірів часу роботи алгоритма


#define rejected_number 2     // Кількість відкинутих початкових вимірів


#define min_max_number 3       // Кількість відкинутих вимірів з мінімільними значеннями.
                               // Вона ж дорівнює кількості відкинутих вимірів
                               // з максимальними значеннями.


extern clock_t  Res[measurements_number];    // Масив значень часу роботи алгоритма


float MeasurementProcessing();      // Функція обробки і усереднення значень вимірів
                                    // часу роботи алгоритма.
                                    // Повертає усереднене значення часу роботи алгоритма.



void fill_res_select4(void);
void fill_res_select(void);

void fill_res_select_vector(void);
void fill_res_select4_vector(void);

clock_t sort_quick_arr();
clock_t sort_quick_vector(int order);

void clear_res(void);


#endif //MYCOURSE_MEASUREMENT_H
