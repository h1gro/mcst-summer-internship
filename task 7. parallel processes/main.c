#include <stdio.h>
#include <stdlib.h>
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
    struct stat file_inf = {0};

    stat(argv[1], &file_inf);

    FILE* read_file = fopen(argv[1], "r");

    CheckFile(read_file);

    pid_t ProgramID = fork();

    if (ProgramID == -1)
    {
        printf("fork failed\n");
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

void DoParent(FILE* read_file, size_t read_file_size)
{
    assert(read_file);

    FILE* parent_write = fopen(PARENT_FILE, "w");

    CheckFile(parent_write);

    FileCopy(read_file, parent_write, read_file_size);

    CheckFclose(parent_write);
}

void DoChild(FILE* read_file, size_t read_file_size)
{
    assert(read_file);

    FILE* child_write = fopen(CHILD_FILE, "w");

    CheckFile(child_write);

    FileCopy(read_file, child_write, read_file_size);

    CheckFclose(child_write);
}

void FileCopy(FILE* read_file, FILE* write_file, size_t read_file_size)
{
    assert(read_file);
    assert(write_file);

    fseek(read_file, 0L, SEEK_SET);

    int* interim_buf = (int*) calloc(read_file_size, sizeof(int));

    fread(interim_buf, sizeof(char), read_file_size, read_file);

    fwrite((const void*) interim_buf, sizeof(char), read_file_size, write_file);

    free(interim_buf);
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
