#include <stdio.h>
#include <assert.h>

#include "paral_proc.h"

FILE* DoParent(FILE* read_file, size_t read_file_size)
{
    assert(read_file);

    //open file for parent writing
    FILE* parent_write = fopen(PARENT_FILE, "w+");

    CheckFile(parent_write);

    //FileCopy is coping content of read_file to parent_file
    if (FileCopy(read_file, parent_write, read_file_size) != SUCCESS)
    {
        perror("parent error\n");
    }

    return parent_write;
}

void DoChild(FILE* read_file, size_t read_file_size)
{
    assert(read_file);

    //open file for child writing
    FILE* child_write = fopen(CHILD_FILE, "w+");

    CheckFile(child_write);

    //FileCopy is coping content of read_file to child_file
    if (FileCopy(read_file, child_write, read_file_size) != SUCCESS)
    {
        perror("child error\n");
    }

    printf("---------------Child_proc write in file---------------\n");
    ResultProcesses(child_write, read_file_size); //print contents of the parent file
    //CheckFclose(child_write);
}

int FileCopy(FILE* read_file, FILE* write_file, size_t read_file_size)
{
    assert(read_file);
    assert(write_file);

    //put file ptr at the beggining of the file
    fseek(read_file, 0L, SEEK_SET);

    //create temporary buffer for copying contents of the read file
    char* interim_buf = (char*) calloc(read_file_size, sizeof(char));

    //copying
    size_t fread_return = fread(interim_buf, sizeof(char), read_file_size, read_file);

    //check return value of fread
    _WR_RETURN_(fread_return, FREAD_ERROR);

    //pasting
    size_t fwrite_return = fwrite((const void*) interim_buf, sizeof(char), read_file_size, write_file);

    //check return value of fwrite
    _WR_RETURN_(fwrite_return, FWRITE_ERROR);

    free(interim_buf);

    return SUCCESS;
}

void ResultProcesses(FILE* include_file, size_t read_file_size)
{
    assert(include_file);

    //put file ptr at the beggining of the file
    fseek(include_file, 0L, SEEK_SET);

    //create temporary buffer for copying contents of the read file
    char* interim_buf = (char*) calloc(read_file_size, sizeof(char));

    //coping
    size_t fread_return = fread(interim_buf, sizeof(char), read_file_size, include_file);

    _WR_RETURN_(fread_return, FREAD_ERROR);

    //printf content in standart flow
    for (int i = 0; i < read_file_size; i++)
    {
        fprintf(stdout, "%c", interim_buf[i]);
    }
    printf("\n");

    free(interim_buf);

    CheckFclose(include_file);
}
