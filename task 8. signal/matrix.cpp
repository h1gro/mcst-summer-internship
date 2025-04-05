#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <time.h>
#include <signal.h>

#include "my_signal.h"

void MatrixCtor(struct matrix_t* matrix)
{
    assert(matrix);

    matrix->matrix_size = MATRIX_SIZE;

    matrix->matrix_A = (int*) calloc(matrix->matrix_size * matrix->matrix_size, sizeof(int));
    matrix->matrix_B = (int*) calloc(matrix->matrix_size * matrix->matrix_size, sizeof(int));
    matrix->matrix_C = (int*) calloc(matrix->matrix_size * matrix->matrix_size, sizeof(int));

    matr_C = matrix->matrix_C;

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

    int C_position = 0;

    for (int lines_A = 0; lines_A < matrix->matrix_size; lines_A++)
    {
        for (int column_B = 0; column_B < matrix->matrix_size; column_B++)
        {
            for (int column_A = 0; column_A < matrix->matrix_size; column_A++)
            {
                matrix->matrix_C[C_position] += matrix->matrix_A[lines_A * matrix->matrix_size + column_A] * matrix->matrix_B[column_A * matrix->matrix_size + column_B];
                sleep(1);
            }
            C_position++;
            matrix->cur_column = C_position % matrix->matrix_size;
            CUR_COLUMN = C_position % matrix->matrix_size;
            printf("col = %d, line = %d\n", matrix->cur_column, matrix->cur_line);
        }
        matrix->cur_line++;
        CUR_LINE++;
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
            printf("%5d ", matr[i * MATRIX_SIZE + j]);
        }
        printf("\n");
    }
}

void PrintIterations(int sig)
{
    FILE* output_file = fopen(MATR_FILE, "w");

    CheckFile(output_file);

    printf("\n-------------\nline: %d\ncolumn: %d\n-------------\n", CUR_LINE + 1, CUR_COLUMN + 1);

    fprintf(output_file, "C:\n   ");
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        if (i == CUR_COLUMN)
        {
            fprintf(output_file, "--^-- ");
        }
        else
        {
            fprintf(output_file, "----- ");
        }
    }

    fprintf(output_file, "\n");
    PrintEndMatrix(matr_C, output_file);
    fprintf(output_file, "\n");

    CheckFclose(output_file);

    signal(SIGINT, SIG_DFL);

    if (signal(SIGINT, SigintHandler) == SIG_ERR)
    {
        perror("error!\n");
        exit(0);
    }
}

void SigintHandler(int sig)
{
    printf("\nSecond SIGINT (Ctrl+C) that stopped the programm\n");
    _exit(0);
}

void PrintEndMatrix(int* matrix, FILE* output_file)
{
    assert(matrix);

    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = -1; j < MATRIX_SIZE; j++)
        {
            if ((j == -1) && (i == CUR_LINE))
            {
                fprintf(output_file, "-> ");
            }

            else if (j == -1)
            {
                fprintf(output_file, " | ");
            }

            else
            {
                fprintf(output_file, "%5d ", matrix[i * MATRIX_SIZE + j]);
            }
        }
        fprintf(output_file, "\n");
    }
}
