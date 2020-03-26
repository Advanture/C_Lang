#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#define M 5 /* Число строк матрицы */
#define N 10 /* Число столбцов матрицы */

int main()
{
    int a[M][N];
    int b[N]; /* Минимальное значение для строки */
    int c[N]; /* Максимальное значение для строки */
    int i, j, strmax, strmin, tmp;

    for(i = 0; i < M; i++)
        for(j = 0; j < N; j++)
            a[i][j] = rand()%100;

    for(i = 0; i < M; i++){
        for(j = 0; j < N; j++)
            printf("%5d", a[i][j]);
        printf("\n");
    }

    for(i = 0; i < M; i++){
        int min = INT_MAX;
        int max = INT_MIN;
        strmax = 0;
        strmin = 0;
        tmp = 0;
        for(j = 0; j < N; j++)
        {
            if(a[i][j] < min)
            {
                //printf("%d\t%d\t%d\n",i,j,a[i][j]);
                min = a[i][j];
                b[i] = a[i][j];
                strmin = j;
                //printf("\nbb:%d\t%d", i,j);
            }

            if(a[i][j] > max)
            {
                max = a[i][j];
                c[i] = a[i][j];
                a[i][j] = b[i];
                strmax = j;
            }
        }
        //printf("aa:%d", strmin);
        tmp = a[i][strmin];
        printf("\n%d\t%d\t%d\t%d\t%d", i, a[i][strmax], a[i][strmin], strmax, strmin);
        a[i][strmin] = a[i][strmax];
        a[i][strmax] = tmp;
    }

    printf("-----\n");

    for(i = 0; i < M; i++){
        for(j = 0; j < N; j++)
            printf("%5d", a[i][j]);
        printf("\n");
    }

    for(i = 0; i < M; i++) printf("Str #%d: min: %d\tmax: %d\n", i+1, b[i], c[i]);
    return 0;
}