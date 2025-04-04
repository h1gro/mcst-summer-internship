#ifndef _SIGNAL_
#define _SIGNAL_

struct matrix_t
{
    int* matrix_A;
    int* matrix_B;
    int* matrix_C;
    int  matrix_size;
};

//const int MATRIX_SIZE = 1000000;
const int MATRIX_SIZE = 3;

void sigint_handler(int sig);

void MatrixCtor    (struct matrix_t* matrix);
void CtorArray     (int* array, int size);
void FillingMatrix (int* matrix, int size);
void Multiply      (struct matrix_t* matrix);
#endif
