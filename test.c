#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrice.c"
#include "convolution.c"

int main()
{

    int N = 0; // Taille de la matrice carrée
    int p = 1; // Taille du filtre de convolution (2p+1 x 2p+1)
    int choix;
    int choixCorrect = 0; // boolen du choix
    double trace = 0.0;

    do
    {

        printf("Entrer la taille de votre matrice (la taille doit etre > 5 et impair) :");
        scanf("%d", &N);

    } while ((N < 5) || ((N % 2) == 0));

    printf("\n");

    while ((2 * p + 1) < (N / 3))
    {
        p++;
    };

    p = 2 * p + 1;

    
    int **matriceA = get_random_matrice(N);
    int **matriceKernel = get_random_matrice(p);
    int **result = (int **)malloc(N * sizeof(int *));

    for (int i = 0; i < N; i++)
    {
        result[i] = (int *)malloc(N * sizeof(int));
    }

    trace = trace_matrice(matriceA, N);

    printf("Random matrix A:\n");
    print_matrice(matriceA, N);

    printf("\nTrace: %.3f\n", trace);

    do
    {
        printf("\n\ninEnter la matrice de Kernel :\nManuallement =(1)\nAleatoirement =(2);\n");
        scanf("%d", &choix);
        if (choix == 1 || choix == 2)
        {
            choixCorrect = 1;
        }
    } while (!choixCorrect);

    if (choix == 2)
    {
        printf("Random matrix kernel:\n");
        print_matrice(matriceKernel, p);
    }
    else
    {
        for (int i = 0; i < p; i++)
        {
            for (int j = 0; j < p; j++)
            {
                printf("kernel[%d][%d]:", i, j);
                scanf("%d", matriceKernel[i][j]);
            }
        }
    }

    printf("\n");

    // Appeler la fonction de convolution
    convolution2(matriceA, matriceKernel, result, N, p);

    printf("\nResult matrix :\n");

    print_matrice(result, N);

    // Free memory for the matrix
    for (int i = 0; i < N; i++)
    {
        free(matriceA[i]);
        free(matriceKernel[i]);
        free(result[i]);
    }
    free(matriceA);
    free(matriceKernel);
    free(result);

    return 0;
}
