// Created by sentimental on 4/14/19.

#include "vector_sort.h"


clock_t vector_select()
{
    int Min, imin;
    clock_t time_start, time_stop;
    time_start = clock();
    for(int s=0; s<N-1; s++){
        Min=vector[s]; imin=s;
        for(int i=s+1; i<N; i++)
            if (vector[i]<Min){
                Min=vector[i];
                imin=i;
            }
        vector[imin]=vector[s];
        vector[s]=Min;
    }
    time_stop = clock();
    return time_stop - time_start;
}

clock_t vector_select4()
{
    int L, R, imin, imax, tmp;
    clock_t time_start, time_stop;
    time_start = clock();
    L=0; R=N-1;
    while (L<R){
        imin=L; imax=L;
        for(int i=L+1; i<R+1; i++)
            if (vector[i]<vector[imin]) imin=i;
            else
                if (vector[i]>vector[imax]) imax=i;
        tmp=vector[imin];
        vector[imin]=vector[L];
        vector[L]=tmp;
        if (imax==L) {
            tmp=vector[imin];
            vector[imin]=vector[R];
            vector[R]=tmp;
        }
        else {
            tmp=vector[imax];
            vector[imax]=vector[R];
            vector[R]=tmp;
        }
        L=L+1; R=R-1;
    }
    time_stop = clock();
    return time_stop - time_start;
}

void QuickSort_v(int L, int R)
{
    int  B, tmp, i, j;
    B = vector[(L + R) / 2];
    i = L;
    j = R;
    while (i <= j)
    {
        while (vector[i] < B) i = i + 1;

        while (vector[j] > B) j = j - 1;
        if (i <= j)
        {
            tmp = vector[i];
            vector[i] = vector[j];
            vector[j] = tmp;
            i = i + 1;
            j = j - 1;
        }
    }
    if (L < j) QuickSort_v(L, j);
    if (i < R) QuickSort_v(i, R);
}
