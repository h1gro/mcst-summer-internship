#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <sys/wait.h>
#include <sys/stat.h>

#include "paral_proc.h"
//#include "../stat/header.h"

//before start a programm you may have to write in console:
//dos2unix main.c

int main(int argc, char* argv[])
{
    struct stat file_inf = {0};

    stat(argv[1], &file_inf);

    FILE* read_file = fopen(argv[1], "r");

    CheckFile(read_file);

    pid_t ProgramID = fork();

    if (ProgramID == -1)
    {
        printf("fork failed!\n");
    }

    else if (ProgramID == 0)
    {
        DoChild(read_file, file_inf.st_size);
    }

    else
    {
        DoParent(read_file, file_inf.st_size);
        wait(NULL);
    }

    CheckFclose(read_file);

    return 0;
}
