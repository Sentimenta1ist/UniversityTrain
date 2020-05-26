#include "thread.h"



int main()
{
    sem_init (&SCR1, 0, 0);

    int sem_value;
    sem_getvalue(&SCR1,&sem_value);
    printf("semaphore=%d\n",sem_value);

    int length_at_start=5;
    int i;

    for(i=0;i<length_at_start;i++) {
        PushQue(i);
        sem_post(&SCR1);
    }

    printf("Queue with elements from 0-th to %d-th has been created\n",length_at_start-1);
    sem_getvalue(&SCR1,&sem_value);
    printf("Semaphore = %5d\n",sem_value);
    printf ("\nStart all threads!\n");


    pthread_barrier_init(&BCR2,NULL,2);

    pthread_create (&P6, NULL, &thread_function6, NULL);
    pthread_create (&P3, NULL, &thread_function3, NULL);
    pthread_create (&P1, NULL, &thread_function1, NULL);
    pthread_create (&P2, NULL, &thread_function2, NULL);
    pthread_create (&P4, NULL, &thread_function4, NULL);
    pthread_create (&P5, NULL, &thread_function5, NULL);

    pthread_join(P6,NULL);
    pthread_join(P3,NULL);
    pthread_join(P1,NULL);
    pthread_join(P2,NULL);
    pthread_join(P4,NULL);
    pthread_join(P5,NULL);



    printf("\nAll threads stopped !\n");
    return 0;
}
