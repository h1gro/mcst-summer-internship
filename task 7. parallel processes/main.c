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
    struct stat file_inf = {0}; //init struct stat

    //get information of the main read file
    stat(argv[1], &file_inf);

    FILE* read_file = fopen(argv[1], "r");

    CheckFile(read_file); //check for opening file

    //start parallel processing
    ProcBranching(read_file, &file_inf);

    CheckFclose(read_file);

    return 0;
}

void ProcBranching(FILE* read_file, struct stat* file_inf)
{
    assert(read_file);
    assert(file_inf);

    int status = 0;
    pid_t ProgramID = fork(); //create child-proc

    if (ProgramID == -1)
    {
        printf("fork failed!\n");
    }

    else if (ProgramID == 0)
    {
        DoChild(read_file, file_inf->st_size);
    }

    else
    {
        pid_t wait_ret = wait(&status); //wait() - waiting ending of child process 

        if (wait_ret != -1) //check for ending child process
        {
            FILE* parent_file = DoParent(read_file, file_inf->st_size);
            printf("---------------Parent_proc write in file---------------\n");
            ResultProcesses(parent_file, file_inf->st_size); //print contents of the parent file
        }
    }
}
