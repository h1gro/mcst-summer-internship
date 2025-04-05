#include "my_signal.h"

int main()
{
    struct matrix_t matrix = {};
    struct sigaction sig   = {};

    sig.sa_sigaction = PrintIterations;
    sig.sa_flags     = SA_SIGINFO;

    if (sigaction(SIGINT, &sig, NULL) == -1) {
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
