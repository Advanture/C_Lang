#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#define M 5 /* Число строк матрицы */
#define N 10 /* Число столбцов матрицы */

int main()
{
    int a[M][N];
    int b[N]; /* Число минимумов = число стобцов */
    int i, j;

    for(i = 0; i < M; i++)
        for(j = 0; j < N; j++)
            a[i][j] = rand()%100;

    for(i = 0; i < N; i++){
        int min = INT_MAX;
        for(j = 0; j < M; j++)
        {
            if(a[j][i] < min)
            {
                //printf("%d\t%d\t%d\n",i,j,a[j][i]);
                min = a[j][i];
                b[i] = a[j][i];
            }
        }
    }

    for(i = 0; i < M; i++){
        for(j = 0; j < N; j++)
            printf("%5d", a[i][j]);
        printf("\n");
    }

    for(i = 0; i < N; i++) printf("%d\t", b[i]);
    return 0;
}