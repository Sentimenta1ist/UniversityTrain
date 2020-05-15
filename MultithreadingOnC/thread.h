#ifndef PRO_LAB4_THREAD_H
#define PRO_LAB4_THREAD_H

#include "queue.h"

/*
    type __sync_fetch_and_add (type *ptr, type value)
    type __sync_sub_and_fetch (type *ptr, type value)
    type __sync_or_and_fetch (type *ptr, type value)

    type __sync_fetch_and_and (type *ptr, type value)
    type __sync_fetch_and_nand (type *ptr, type value)
    type __sync_or_and_fetch (type *ptr, type value)
    type __sync_xor_and_fetch (type *ptr, type value)

    bool __sync_bool_compare_and_swap(type *ptr, type oldval, type newval)
    type __sync_val_compare_and_swap (type *ptr, type oldval, type newval)
 */


void *thread_function6(void *arg) {
    printf("\nP6(Producer) started:\n");
    int k = 1;
    //int num = *(int*)arg;
    int Semaphore_value;
    while (1) {
        if(FullQue())k *=2;
        if (head == NULL) {
            break;
        };
        if (pthread_mutex_trylock(&MCR1) == 0) {
            sem_getvalue(&SCR1, &Semaphore_value);
            if (Semaphore_value < max_queue_length) {
                PushQue(tail->data + 1);
                printf("P6 (Producer): Semaphore = %d; "
                       "Element %d CREATED; \n", Semaphore_value, tail->data);
                sem_post(&SCR1);
            }

            pthread_mutex_unlock(&MCR1);
        }
        usleep(k);
    }

    //pthread_cancel(P3);
    //pthread_cancel(P1);

    printf("P6 (Producer) ends %d\n");
    return NULL;
}

void *thread_function1(void *arg) {
    printf("\nP1 started:\n");
    int i = 0;
    while (1) {
        if( i > max_numbers_of_buf)break;
        i++;
        __sync_or_and_fetch(&unsigned_long_1, 4);
        __sync_fetch_and_add(&long_1, 7);
        __sync_sub_and_fetch(&unsigned_1, 7);
        __sync_xor_and_fetch(&int_1, 7);
        printf("P1:Modification is done\n");


        printf("P1: waits for the P4 at the barrier BCR2\n");
        pthread_barrier_wait(&BCR2);
        printf("P1: works after barrier\n");

        printf("\nP1:"
               " sends signal sig21 for the P2 and P5\n");

        pthread_mutex_lock(&mutSIG);
        flag2 = 1;
        flag5 = 1;
        pthread_cond_signal(&SIG21);
        pthread_mutex_unlock(&mutSIG);

        printf("\nP1:Signal sig21 is sent!\n");

        printf("P1:Get and modification:\n");
        long long_first = __sync_fetch_and_and(&long_2, 0);
        printf("P1: long_2 = %ld\n", long_first);
        long long_second = __sync_fetch_and_add(&long_1, 5);
        printf("P1: long_1 = %ld\n", long_second);
        int first = __sync_fetch_and_xor(&int_2, 0);
        printf("P1: int_2 = %d\n", first);
        long second = __sync_fetch_and_sub(&long_1, 0);
        printf("P1: long_1 = %ld\n", second);
    }
    flagOfEnd--;
    printf("P1 ends\n\n");
    return NULL;
}

void *thread_function2(void *arg) {
    printf("\nP2 started:\n");
    int i = 0;
    while(1)
    {
        if(flagOfEnd == 0) break;
        printf("P2: start wait...");
        if( i > max_numbers_of_buf)break;
        i++;
        pthread_mutex_lock(&mutSIG);
        if(!max_numbers_of_buf)break;
        while (flag2 == 0) {
            if(!max_numbers_of_buf)break;
            printf("P2: is waiting for sig21\n");
            pthread_cond_wait(&SIG21, &mutSIG);
        }
        printf("\nP2: gets sig21\n");
        flag2 = 0;
        pthread_mutex_unlock(&mutSIG);

        //modification
        printf("P2:Getting and record to buffer:\n");


        unsigned first = __sync_fetch_and_and(&unsigned_1, 4); // using var
        printf("P2: Unsigned_1 = %d\n", first);
        unsigned second = __sync_fetch_and_add(&unsigned_2, 0);
        printf("P2: Unsigned_2= %d\n", second);
        unsigned long long_first = __sync_and_and_fetch(&unsigned_long_1, 0);
        printf("P2: UnsignedLong_1 = %lu\n", long_first);
        unsigned long l_second = __sync_fetch_and_add(&unsigned_long_2, 0);
        printf("P2: UnsignedLong2_1 = %lu\n", l_second);
        __sync_val_compare_and_swap(&int_2, 0, 1);
        printf("P2: changed int_2 = %d\n", int_2);


        //record to the buffer;
        int Semaphore_value;
        if (pthread_mutex_trylock(&MCR1) == 0) {
            sem_getvalue(&SCR1, &Semaphore_value);
            if (Semaphore_value < max_queue_length) {
                PushQue(tail->data + 1);
                printf("P2: (Producer) semaphore=%d; "
                       "element %d CREATED; \n",
                       Semaphore_value, tail->data);
                sem_post(&SCR1);
            }

            pthread_mutex_unlock(&MCR1);
        }



    }
    printf("P2 ends\n");
    return NULL;
}

void *thread_function4(void *arg) {
    printf("\nP4 started:\n");
    int i = 0;
    while (1) {
        if(i > max_numbers_of_buf) break;
        i++;
        __sync_fetch_and_add(&unsigned_long_1, 4);
        __sync_fetch_and_add(&long_1, 7);
        __sync_sub_and_fetch(&unsigned_1, 7);
        __sync_sub_and_fetch(&int_1, 7);
        printf("P4:Modification is done\n");

        printf("P4: waits for the P1 at the barrier BCR2\n");
        pthread_barrier_wait(&BCR2);
        printf("P4: works after barrier\n");
        printf("\nP4: sends signal sig21 for the P2 and P5\n");

        pthread_mutex_lock(&mutSIG);
        flag2 = 1;
        flag5 = 1;
        pthread_cond_signal(&SIG21);
        pthread_mutex_unlock(&mutSIG);

        printf("\nP4: Signal sig21 is sent!\n");

        printf("P4: Get and modification\n");
        long long_first = __sync_fetch_and_and(&long_2, 0);
        printf("P4: long_2 = %ld\n", long_first);
        long long_second = __sync_fetch_and_add(&long_1, 5);
        printf("P4: long_1 = %ld\n", long_second);
        int first = __sync_fetch_and_xor(&int_2, 0);
        printf("P4: int_2 = %d\n", first);
        long second = __sync_fetch_and_sub(&long_1, 0);
        printf("P4: long_1 = %ld\n", second);

    }
    flagOfEnd--;
    printf("P4 ends\n\n");
    return NULL;
}

void *thread_function5(void *arg) {
    printf("\nP5 started:\n");
    int i = 0;
    while(1)
    {
        if(flagOfEnd == 0) break;
        printf("P5: start wait... %d ", flagOfEnd);
        if( i > max_numbers_of_buf)break;
        i++;
        pthread_mutex_lock(&mutSIG);
        if(!max_numbers_of_buf)break;
        while (flag5 == 0) {
            if(!max_numbers_of_buf)break;
            printf("P5: is waiting for sig21\n");
            pthread_cond_wait(&SIG21, &mutSIG);
        }
        printf("\nP5: gets sig21\n");
        flag5 = 0;
        pthread_mutex_unlock(&mutSIG);

        //modification
        printf("P5: Getting and record to buffer:\n");
        unsigned first = __sync_fetch_and_and(&unsigned_1, 4); // using var
        printf("P5: Unsigned_1 = %d\n", first);
        unsigned second = __sync_fetch_and_add(&unsigned_2, 0);
        printf("P5: Unsigned_2= %d\n", second);
        unsigned long long_first = __sync_and_and_fetch(&unsigned_long_1, 0);
        printf("P5: UnsignedLong_1 = %lu\n", long_first);
        unsigned long l_second = __sync_fetch_and_add(&unsigned_long_2, 0);
        printf("P5: UnsignedLong2_1 = %lu\n", l_second);
        __sync_val_compare_and_swap(&int_2, 0, 1);
        printf("P5: changed int_2 = %d\n", int_2);


        //record to the buffer;
        int Semaphore_value;
        if (pthread_mutex_trylock(&MCR1) == 0) {
            sem_getvalue(&SCR1, &Semaphore_value);
            if (Semaphore_value < max_queue_length) {
                PushQue(tail->data + 1);
                printf("P5 (Producer): semaphore=%d; "
                       "element %d CREATED; \n",
                       Semaphore_value, tail->data);
                sem_post(&SCR1);
            }

            pthread_mutex_unlock(&MCR1);
        }



    }
    printf("P5 ends\n");
    return NULL;
}

void *thread_function3(void *arg) {
    printf("\nP3(Consumer) started:\n");
    struct node_t *element = NULL;
    int Semaphore_value;

    while (1) {
        int k = 8;
        if(max_numbers_of_buf == 0) break;
        if(EmptyQue()&&max_numbers_of_buf) {
           // k = max_numbers_of_buf;
            max_numbers_of_buf--;
        }
        element = NULL;
        if (pthread_mutex_trylock(&MCR1) == 0) {
            if (sem_trywait(&SCR1) == 0) {
                element = (struct node_t *) PopQue();
                sem_getvalue(&SCR1, &Semaphore_value);
                printf("P3 (Consumer): Semaphore = %d; Element %d TAKEN; \n",
                       Semaphore_value, element->data);
            }
            pthread_mutex_unlock(&MCR1);
        }
        if (element != NULL) {
            free(element);
        }
        usleep(k);
    }


    printf("P3 (Consumer) ends\n");
    return NULL;
}

#endif //PRO_LAB4_THREAD_H
