#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <sys/wait.h>
#include <sys/stat.h>

#include "paral_proc.h"
#include "../stat/header.h"
//before start a programm you may have to write in console:
//dos2unix main.c

int main(int argc, char* argv[])
{
    FILE* read_file = fopen(argv[1], "r");

    CheckFile(read_file);

    pid_t ProgramID = fork();

    if (ProgramID == -1)
    {
        printf("fork failed\n");
    }

    else if (ProgramID == 0)
    {
        DoChild(read_file);
    }

    else
    {
        DoParent(read_file);
        wait(NULL);
    }

    CheckFclose(read_file);

    return 0;
}

void DoParent (FILE* read_file)
{
    assert(read_file);

    FILE* parent_write = fopen(PARENT_FILE, "w");

    CheckFile(parent_write);

    

    CheckFclose(parent_write);
}

void DoChild (FILE* read_file)
{
}

int CheckFile(FILE* file)
{
    if (file == NULL)
    {
        printf("file not opened\n");
        return CHECK_FILE_ERROR;
    }

    return CHECK_FILE_OK;
}

void CheckFclose(FILE* file_ptr)
{
    assert(file_ptr);

    int fclose_return = fclose(file_ptr);

    if (fclose_return != 0)
    {
        printf("file closed wrong, fclose_return = %d\n", fclose_return);
    }
}
