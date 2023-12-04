#include "convolution.h"

void convolution(int **matriceA, int **matriceB, int **result, int N, int p)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            result[i][j] = 0;
            for (int m1 = i, m2 = 0; m1 < i + p && m1 < N; m1++, m2++)
            {
                for (int n1 = j, n2 = 0; n1 < j + p && n1 < N; n1++, n2++)
                {
                    result[i][j] += (int)matriceA[m1][n1] * matriceB[m2][n2];
                }
            }
        }
    }
}

void convolution2(int **matriceA, int **matriceB, int **result, int N, int p)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            result[i][j] = 0;
            
            // printf("\nCentered at matrice[%d][%d]:\n", i, j);
            for (int m1 = i - p/2  , m2 = 0; m1 <= i + p/2 && m1 < N; m1++ , m2++) {
                
                for (int n1 = j - p/2 ,n2 = 0; n1 <= j + p/2 && n1 < N; n1++ , n2++) {
                    if(m1 < 0 || n1<0){
                        continue;
                    }else{
                        // printf("%d ", matriceA[m1][n1]);
                        result[i][j] += (int)matriceA[m1][n1] * matriceB[m2][n2];
                    }
                    
                }
                // printf("\n");
            }
        }
    }
}
