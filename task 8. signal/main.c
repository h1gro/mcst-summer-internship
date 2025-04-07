#include "my_signal.h"

int main()
{
    struct matrix_t matrix = {0}; //struct matrix
    struct sigaction sig   = {0}; //init struct sigation

    //PrintIteration - name of function that get control
    sig.sa_sigaction = PrintIterations;
    sig.sa_flags     = SA_SIGINFO;

    //sigaction wait interruption of the program (exact Ctrl+C)
    if (sigaction(SIGINT, &sig, NULL) == -1) {
        perror("Ошибка signal()");
        return 1;
    }

    //Ctor matrixes
    MatrixCtor(&matrix);

    //Multiply matrixes A and B
    Multiply(&matrix);


//print all matrixes:
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
//end print

    //Dtor matrixes
    MatrixDtor(&matrix);

    return 0;
}
