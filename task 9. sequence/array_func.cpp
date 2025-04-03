#include "sequence.h"

void FindMaxSum(struct seq_t* sequence)
{
    assert(sequence);

    int local_sum = 0;
    int i = 0;

    /*cycle for going 1 time for all array
    and check sum of subsequences

    default:
    NUMBER_ELEMS = 10
    sequence->max_sum = -1000*/
    for (i = 0; i < NUMBER_ELEMS - 1; i++)
    {
        if (sequence->numbers[i] < sequence->numbers[i + 1]) //check for increase
        {
            local_sum += sequence->numbers[i];
        }

        else if (local_sum > sequence->max_sum) //if subsequence is end compare it's local_sum with sequence->max_sum
        {
            //if subsequence's sum bigger than assign sequence->max_sum
            sequence->max_sum = local_sum + sequence->numbers[i];
            local_sum = 0;
        }

        else
        {
            local_sum = 0;
        }
    }

    if (local_sum > sequence->max_sum) // if for the last sequence of array
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

    //filling array by users numbers
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

    //allocate memory for massive int*
    sequence->numbers = (int*) calloc(NUMBER_ELEMS, sizeof(int));

    assert(sequence->numbers);

    //FICT_sum - default sum of max_sum = -1000
    sequence->max_sum = FICT_SUM;
}

void SequenceDtor(struct seq_t* sequence)
{
    assert(sequence);

    //free up memory
    free(sequence->numbers);
}
