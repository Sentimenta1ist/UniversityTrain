#include "base.h"

void PrintMatrix(double** Matrix, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0;j < n; j++){
            printf(" %3.0f",Matrix[i][j]);
        }
        printf("\n");
    }
}
