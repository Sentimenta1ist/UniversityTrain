#include "task.h"

double** FindAndReplace(double** A,int n,int debug){
    printf("\n");
    int i_first_max = 0;
    int i_last_min = 0;
    int value_first_max = A[0][n-1], value_last_min = A[0][n-1];

    if(debug){
        printf("Task Func \n");
        printf("Minor diagonal:\n");
        for(int i = 0; i < n; i++){
            for(int j = 0 ; j < n - 1 - i; j++){
                printf("    ");
            }
            printf("%3.0f \n", A[i][n - 1 - i]);
        }
        printf("\n");

        for(int i = 0; i < n; i++){
            if(A[i][n - 1 - i] > value_first_max){
                i_first_max = i;
                value_first_max = A[i][n - 1 - i];
                printf(" new max ->");
            }
            if(A[i][n - 1 - i] <= value_last_min){
                i_last_min = i;
                value_last_min = A[i][n - 1 - i];
                printf(" new min ->");
            }
            printf("%3.0f \n", A[i][n - 1 - i]);
        }
        printf("\n");
        printf("First max index was - %d;%d  \nLast min index was - %d;%d", i_first_max, n - 1 - i_first_max, i_last_min, n - 1 - i_last_min);
        printf("\nEnd Task Func\n\n");
    }
    else{
        for(int i = 0; i < n; i++){
            if(A[i][n - 1 - i] > value_first_max){
                i_first_max = i;
                value_first_max = A[i][n - 1 - i];
            }
            if(A[i][n - 1 - i] <= value_last_min){
                i_last_min = i;
                value_last_min = A[i][n - 1 - i];
            }

        }
    }

    A[i_first_max][ n - 1 - i_first_max] = value_last_min;
    A[i_last_min][ n - 1 - i_last_min] = value_first_max;
    return A;
}
