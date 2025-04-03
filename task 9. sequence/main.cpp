#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "sequence.h"

int main()
{
    struct seq_t sequence = {};

    SequenceCtor(&sequence);

    FillArray(sequence.numbers);

    PrintArray(sequence.numbers);

    SequenceDtor(&sequence);

    return 0;
}

void FillArray(int* array)
{
    assert(array);

    printf("----------Please, enter elements of sequence----------\n");

    for (int i = 0; i < NUMBER_ELEMS; i++)
    {
        scanf("%d", &array[i]);
    }
}

void PrintArray(int* array)
{
    assert(array);

    printf("----------Sequence----------\n");

    for (int i = 0; i < NUMBER_ELEMS; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void SequenceCtor(struct seq_t* sequence)
{
    assert(sequence);

    sequence->numbers = (int*) calloc(NUMBER_ELEMS, sizeof(int));

    assert(sequence->numbers);

    sequence->max_sum = FICT_SUM;
}

void SequenceDtor(struct seq_t* sequence)
{
    assert(sequence);

    free(sequence->numbers);
}
