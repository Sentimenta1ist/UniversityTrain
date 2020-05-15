// Created by sentimental on 4/14/19.

#include "array_sort.h"

clock_t sort_selection_arr()
{
    int Min, imin, temp,index_of_sum = 0;
    clock_t time_start, time_stop;
    memory_vector_of_sum();
    fill_vector_of_sum();

    time_start = clock();

    for(int k = 0; k < P; k++ )
    {

        for(int j_sum = 0; j_sum < N; j_sum++){      // рахування вектора сум стовбчиків
            for(int i_sum = 0; i_sum < M; i_sum++){
                vector_of_sum[index_of_sum] += arr[k][i_sum][j_sum];
            }
        index_of_sum++;
        }

        for(int s=0; s<N-1; s++)
        {
            Min=vector_of_sum[s]; imin=s;
            for(int i=s+1; i<N; i++)
                if (vector_of_sum[i]<Min){
                    Min=vector_of_sum[i];
                    imin=i;
                }

            vector_of_sum[imin]=vector_of_sum[s];
            vector_of_sum[s]=Min;

            for (int i = 0; i < M; i++)         // копіювання стовпчиків використовуючи вектор сум як вектор ключів
            {
                temp = arr[k][i][imin];
                arr[k][i][imin] = arr[k][i][s];
                arr[k][i][s] = temp;
            }
        }
        index_of_sum = 0;
    }
    free_vector_of_sum();
    time_stop = clock();
    return time_stop - time_start;
}

clock_t sort_selection_4_arr()
{
    int L,R,tmp, imin,imax, temp,index_of_sum = 0;
    clock_t time_start, time_stop;
    memory_vector_of_sum();
    fill_vector_of_sum();

    time_start = clock();

    for(int k = 0; k < P; k++ )
    {

        for(int j_sum = 0; j_sum < N; j_sum++){
            for(int i_sum = 0; i_sum < M; i_sum++){
                vector_of_sum[index_of_sum] += arr[k][i_sum][j_sum];
            }
            index_of_sum++;
        }

        L=0; R=N-1;
        while (L<R){
            imin=L; imax=L;
            for(int i=L+1; i<R+1; i++)
                if (vector_of_sum[i]<vector_of_sum[imin]) imin=i;
                else
                if (vector_of_sum[i]>vector_of_sum[imax]) imax=i;

            tmp=vector_of_sum[imin];
            vector_of_sum[imin]=vector_of_sum[L];
            vector_of_sum[L]=tmp;

            for(int i = 0;i < M;i++)
            {
                temp = arr[k][i][imin];
                arr[k][i][imin] = arr[k][i][L];
                arr[k][i][L] = temp;
            }

            if (imax==L) {
                tmp=vector_of_sum[imin];
                vector_of_sum[imin]=vector_of_sum[R];
                vector_of_sum[R]=tmp;

                for(int i = 0;i < M;i++)
                {
                    temp = arr[k][i][imin];
                    arr[k][i][imin] = arr[k][i][R];
                    arr[k][i][R] = temp;
                }
            }
            else {
                tmp=vector_of_sum[imax];
                vector_of_sum[imax]=vector_of_sum[R];
                vector_of_sum[R]=tmp;

                for(int i = 0;i < M;i++)
                {
                    temp = arr[k][i][imax];
                    arr[k][i][imax] = arr[k][i][R];
                    arr[k][i][R] = temp;
                }
            }
            L=L+1; R=R-1;
        }

        index_of_sum = 0;
    }
    free_vector_of_sum();
    time_stop = clock();
    return time_stop - time_start;
}

void QuickSort(int L, int R, int slice)
{
    int  B, tmp, i, j,temp;
    B = vector_of_sum[(L + R) / 2];
    i = L;
    j = R;
    while (i <= j)
        {
            while (vector_of_sum[i] < B) i = i + 1;

            while (vector_of_sum[j] > B) j = j - 1;
            if (i <= j)
            {
                tmp = vector_of_sum[i];
                vector_of_sum[i] = vector_of_sum[j];
                vector_of_sum[j] = tmp;
                for(int row = 0; row < M; row++)
                {
                    temp = arr[slice][row][i];
                    arr[slice][row][i] = arr[slice][row][j];
                    arr[slice][row][j] = temp;
                }
                i = i + 1;
                j = j - 1;
            }
        }
        if (L < j) QuickSort(L, j,slice);
        if (i < R) QuickSort(i, R,slice);
}
