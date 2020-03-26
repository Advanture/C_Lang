#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 5 /* Число строк матрицы */
#define N 10 /* Число столбцов матрицы */

int main()
{
    int a[M][N];
    int b[N]; /* Число минимумов = число стобцов */
    int i, j, c = 0;

    srand(time(NULL));

    for(i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            a[i][j] = rand() % 100;
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }


    for(i = 0; i < N; i++){
        j = 0;
        c = 0;
        while(j < N){
            if(a[j][i] % 2 == 0){
                c++;
                if(c == 5){
                    printf("Column #%d has only odd numbers", i+1);
                    return 0;
                }
            } else {
                break;
            }
            j++;
        }
    }

    printf("There are no any columns with only odd numbers.");
    return 0;
}