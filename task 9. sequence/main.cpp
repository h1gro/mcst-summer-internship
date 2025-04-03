#include "sequence.h"

int main()
{
    struct seq_t sequence = {};

    SequenceCtor(&sequence); //constructor for sequence

    FillArray(sequence.numbers); //filling array by numbers from user

    FindMaxSum(&sequence); //func that definds maximum sum of increasing sequence

    //PrintArray(sequence.numbers); //Debug printf all massive

    SequenceDtor(&sequence); //destructor for sequence

    return 0;
}
