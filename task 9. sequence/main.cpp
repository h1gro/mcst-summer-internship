#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "sequence.h"

int main()
{
    struct seq_t sequence = {};

    SequenceCtor(&sequence);

    FillArray(sequence.numbers);

    FindMaxSum(&sequence);

    PrintArray(sequence.numbers);

    SequenceDtor(&sequence);

    return 0;
}

void FindMaxSum(struct seq_t* sequence)
{
    assert(sequence);

    int local_sum = 0;
    int i = 0;

    for (i = 0; i < NUMBER_ELEMS - 1; i++)
    {
        if (sequence->numbers[i] < sequence->numbers[i + 1])
        {
            local_sum += sequence->numbers[i];
            printf("local_sum = %d\n", local_sum);
        }

        else if (local_sum > sequence->max_sum)
        {
            sequence->max_sum = local_sum + sequence->numbers[i];
            local_sum = 0;
        }

        else
        {
            local_sum = 0;
        }

    }

    if (local_sum > sequence->max_sum)
    {
        sequence->max_sum = local_sum;
        local_sum = 0;
    }

    printf("seq_sum = %d\n", sequence->max_sum);
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
