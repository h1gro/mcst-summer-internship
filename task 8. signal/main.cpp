#include <stdio.h>
#include <signal.h>
#include <unistd.h>

#include "my_signal.h"

int main()
{
    struct matrix_t matrix = {};
    //glob_matrix = &matrix;

    if (signal(SIGINT, print_iterations) == SIG_ERR) {
        perror("Ошибка signal()");
        return 1;
    }

    MatrixCtor(&matrix);

    Multiply(&matrix);

    printf("A:\n");
    PrintMatrix(matrix.matrix_A);
    printf("\n");

    printf("B:\n");
    PrintMatrix(matrix.matrix_B);
    printf("\n");

    printf("C:\n");
    PrintMatrix(matrix.matrix_C);
    printf("\n");
    printf("DONE\n");
    MatrixDtor(&matrix);

    return 0;
}

void sigint_handler(int sig)
{
    printf("\nПерехвачен SIGINT (Ctrl+C)\n");
    _exit(0);
}
