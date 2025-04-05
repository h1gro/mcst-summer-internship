#ifndef _SIGNAL_
#define _SIGNAL_

struct matrix_t
{
    int* matrix_A;
    int* matrix_B;
    int* matrix_C;
    int  matrix_size;
    int  cur_line;
    int  cur_column;
};

//const int MATRIX_SIZE = 1000000;
const int MATRIX_SIZE = 5;

static int CUR_COLUMN = 0;
static int CUR_LINE   = 0;
static int* C = NULL;

static struct matrix_t* glob_matrix = NULL;

void sigint_handler   (int sig);
void print_iterations (int sig);

void MatrixDtor    (struct matrix_t* matrix);
void MatrixCtor    (struct matrix_t* matrix);
void CtorArray     (int* array, int size);
void FillingMatrix (int* matrix, int size);
void Multiply      (struct matrix_t* matrix);
void PrintMatrix   (int* matr);
#endif
