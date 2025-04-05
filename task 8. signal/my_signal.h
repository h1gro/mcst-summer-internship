#ifndef _SIGNAL_
#define _SIGNAL_

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>

struct matrix_t
{
    int* matrix_A;
    int* matrix_B;
    int* matrix_C;
    int  matrix_size;
    int  cur_line;
    int  cur_column;
};

enum check_file_consts
{
    CHECK_FILE_ERROR = 1,
    CHECK_FILE_OK    = 0,
};

//const int MATRIX_SIZE = 1000000;
const int MATRIX_SIZE = 5;
static const char* MATR_FILE = "output_matrix.txt";

static int CUR_COLUMN = 0;
static int CUR_LINE   = 0;

static int* matr_C = NULL;

static struct matrix_t* glob_matrix = NULL;

void SigintHandler   (int sig);
void PrintIterations (int sig, siginfo_t* info, void* context);
void PrintEndMatrix  (int* matrix, FILE* output_file);
void MatrixDtor      (struct matrix_t* matrix);
void MatrixCtor      (struct matrix_t* matrix);
void FillingMatrix   (int* matrix, int size);
void Multiply        (struct matrix_t* matrix);
void PrintMatrix     (int* matr);
void CheckFclose     (FILE* file_ptr);

int CheckFile (FILE* file);

#endif
