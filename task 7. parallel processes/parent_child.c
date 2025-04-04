#include <stdio.h>
#include <assert.h>

#include "paral_proc.h"

void DoParent(FILE* read_file, size_t read_file_size)
{
    assert(read_file);

    FILE* parent_write = fopen(PARENT_FILE, "w");

    CheckFile(parent_write);

    if (FileCopy(read_file, parent_write, read_file_size) != SUCCESS)
    {
        perror("parent error\n");
    }

    //CheckFclose(parent_write);
}

void DoChild(FILE* read_file, size_t read_file_size)
{
    assert(read_file);

    FILE* child_write = fopen(CHILD_FILE, "w+");

    CheckFile(child_write);

    if (FileCopy(read_file, child_write, read_file_size) != SUCCESS)
    {
        perror("child error\n");
    }

    printf("---------------Child_proc write in file---------------\n");
    fseek(child_write, 0L, SEEK_SET);
    ResultProcesses(child_write, read_file_size);
    //CheckFclose(child_write);
}

int FileCopy(FILE* read_file, FILE* write_file, size_t read_file_size)
{
    assert(read_file);
    assert(write_file);

    fseek(read_file, 0L, SEEK_SET);

    char* interim_buf = (char*) calloc(read_file_size, sizeof(char));

    size_t fread_return = fread(interim_buf, sizeof(char), read_file_size, read_file);

    _WR_RETURN_(fread_return, FREAD_ERROR);

    size_t fwrite_return = fwrite((const void*) interim_buf, sizeof(char), read_file_size, write_file);

    _WR_RETURN_(fwrite_return, FWRITE_ERROR);

    free(interim_buf);

    return SUCCESS;
}

void ResultProcesses(FILE* include_file, size_t read_file_size)
{
    assert(include_file);

    char* interim_buf = (char*) calloc(read_file_size, sizeof(char));

    size_t fread_return = fread(interim_buf, sizeof(char), read_file_size, include_file);

    _WR_RETURN_(fread_return, FREAD_ERROR);

    for (int i = 0; i < read_file_size; i++)
    {
        printf("%c", interim_buf[i]);
    }
    printf("\n");

    free(interim_buf);

    CheckFclose(include_file);
}
