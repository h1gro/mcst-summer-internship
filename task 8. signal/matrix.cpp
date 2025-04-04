#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "my_signal.h"

void MatrixCtor(struct matrix_t* matrix)
{
    assert(matrix);

    matrix->matrix_size = MATRIX_SIZE * MATRIX_SIZE;

    CtorArray(matrix->matrix_A,  matrix->matrix_size);
    CtorArray(matrix->matrix_B,  matrix->matrix_size);
    CtorArray(matrix->matrix_B,  matrix->matrix_size);
}

void CtorArray(int* array, int size)
{
    array = (int*) calloc(size, sizeof(int));

    assert(array);

    FillingMatrix(array, size);
}

void FillingMatrix(int* matrix, int size)
{
    assert(matrix);

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &matrix[i]);
    }
}

void Multiply(struct matrix_t* matrix)
{
    assert(matrix);
    assert(matrix->matrix_A);
    assert(matrix->matrix_C);
    assert(matrix->matrix_B);

    for (int i = 0; i < matrix->matrix_size; i++)
    {
        for (int j = 0, k = 0; j < matrix->matrix_size, k < matrix->matrix_size; j++, k++)
        {

        }
    }
}
/*
1 2   4 5
1 3   5 7    */
