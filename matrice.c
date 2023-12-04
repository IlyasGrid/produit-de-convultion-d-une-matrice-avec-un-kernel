#include "matrice.h"
#include <time.h>


int **get_random_matrice(int N)
{
    srand(time(NULL));
    int **matrice = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++)
    {
        matrice[i] = (int *)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++)
        {
            matrice[i][j] = rand() % 11 - 5; //  valeur alearatoire de -5 vers 5
        }
    }
    return matrice;
}

double trace_matrice(int **matrice, int N)
{
    double trace = 0.0;
    for (int i = 0; i < N; i++)
    {
        trace += matrice[i][i];
    }
    return trace;
}

void print_matrice(int **matrice, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d\t", matrice[i][j]);
        }
        printf("\n");
    }
}