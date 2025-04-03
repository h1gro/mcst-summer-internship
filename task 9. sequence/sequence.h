#ifndef _SEQUENCE_
#define _SEQUENCE_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct seq_t
{
    int* numbers;
    int  max_sum;
};

const int NUMBER_ELEMS = 10;
const int FICT_SUM     = -1000;

void FindMaxSum   (struct seq_t* sequence);
void SequenceCtor (struct seq_t* sequence);
void SequenceDtor (struct seq_t* sequence);
void FillArray    (int* array);
void PrintArray   (int* array);

#endif
