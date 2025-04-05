#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <time.h>

#include "my_signal.h"

void MatrixCtor(struct matrix_t* matrix)
{
    assert(matrix);

    matrix->matrix_size = MATRIX_SIZE;

    //CtorArray(matrix->matrix_A,  matrix->matrix_size);
    //CtorArray(matrix->matrix_B,  matrix->matrix_size);
    //CtorArray(matrix->matrix_C,  matrix->matrix_size);

    matrix->matrix_A = (int*) calloc(matrix->matrix_size * matrix->matrix_size, sizeof(int));
    matrix->matrix_B = (int*) calloc(matrix->matrix_size * matrix->matrix_size, sizeof(int));
    matrix->matrix_C = (int*) calloc(matrix->matrix_size * matrix->matrix_size, sizeof(int));

    assert(matrix->matrix_A);
    assert(matrix->matrix_B);
    assert(matrix->matrix_C);

    srand(time(NULL));

    FillingMatrix(matrix->matrix_A, matrix->matrix_size * matrix->matrix_size);
    FillingMatrix(matrix->matrix_B, matrix->matrix_size * matrix->matrix_size);
}

void MatrixDtor(struct matrix_t* matrix)
{
    assert(matrix);

    free(matrix->matrix_A);
    free(matrix->matrix_B);
    free(matrix->matrix_C);
}

void CtorArray(int* array, int size)
{
    array = (int*) calloc(size, sizeof(int));

    assert(array);

    //FillingMatrix(array, size);
}

void FillingMatrix(int* matrix, int size)
{
    assert(matrix);

    for (int i = 0; i < size; i++)
    {
        //scanf("%d", &matrix[i]);
        matrix[i] = rand() % 100;
    }
}

void Multiply(struct matrix_t* matrix)
{
    assert(matrix);
    assert(matrix->matrix_A);
    assert(matrix->matrix_B);
    assert(matrix->matrix_C);

    int k = 0;

    for (int lines_A = 0; lines_A < matrix->matrix_size; lines_A++)
    {
        for (int column_B = 0; column_B < matrix->matrix_size; column_B++)
        {
            for (int column_A = 0; column_A < matrix->matrix_size; column_A++)
            {
                matrix->matrix_C[k] += matrix->matrix_A[lines_A * matrix->matrix_size + column_A] * matrix->matrix_B[column_A * matrix->matrix_size + column_B];
            }
            k++;
        }
    }
}

/*
0 1

1 2    0  4 5   1*4 + 2*5
1 3    1   5 7    */

void PrintMatrix(int* matr)
{
    assert(matr);

    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            printf("%d ", matr[i * MATRIX_SIZE + j]);
        }
        printf("\n");
    }
}
