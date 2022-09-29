#include <stdio.h>
#include <stdlib.h>

void darDimMtz(int *fil, int *col)
{
    printf("Dar numero de filas: \n");
    scanf("%d", fil);

    printf("Dar numero de columnas: \n");
    scanf("%d", col);
}

int **crearMtz(int fil, int col)
{
    int **A;
    int i;
    A = (int **)malloc(fil * sizeof(int *));
    if (A == NULL)
    {
        exit(0);
    }

    for (i = 0; i < fil; i++)
    {
        A[i] = (int *)malloc(col * sizeof(int));
    }

    return A;
}

void darDatosMtz(int **A, int fil, int col)
{
    int i, j;
    printf("Ingrese los datos: %d, %d\n", fil, col);
    for (i = 0; i < fil; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("\nA[%d][%d] = ", i + 1, j + 1);
            scanf("%d", &A[i][j]);
        }
    }
}

void showUnidimentionalMtz(int **A, int fil, int col)
{
    int i, j;
    printf("Los datos del arreglo: \n");
    for (i = 0; i < fil; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("\nA[%d][%d] = %d", i + 1, j + 1, A[i][j]);
        }
    }
}

void liberarUnidimentionalMtz(int **A, int fil)
{
    int i;
    for (i = 0; i < fil; i++)
    {
        free(A[i]);
    }
    free(A);
}
