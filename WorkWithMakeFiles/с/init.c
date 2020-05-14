#include "init.h"

double **AllocMatrix(int n){
    double ** Matrix = (double **)malloc(n*sizeof(double *));
    for(int i = 0; i < n; i++) {
        Matrix[i] = (double *)malloc(n*sizeof(double));
    }
    return Matrix;
}

void FillSortMatrix(double** Matrix, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0;j < n; j++){
            Matrix[i][j] = i*n+j + 1;
        }
    }
}

void FillTestMatrix(double** A,int n){
    for(int i = 0; i < n/2; i++){
        for(int j = 0;j < n; j++){
            A[i][j] = 4;
        }
    }
    for(int i = n/2; i < n; i++){
        for(int j = 0;j < n; j++){
            A[i][j] = 8;
        }
    }
}

void FillBackSortMatrix(double** Matrix, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0;j < n; j++){
            Matrix[i][j] = n*n - (i * n +j);
        }
    }
}

void FillRandomMatrix(double** Matrix, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0;j < n; j++){
            Matrix[i][j] = rand() % n*n;
        }
    }
}

//void FillHandMatrix(double** Matrix, int n){
//    for(int i = 0; i < n; i++){
//        for(int j = 0;j < n; j++){
//        	scanf("%lf",Matrix[i][j]);
//        }
//    }
//}

