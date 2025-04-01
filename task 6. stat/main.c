#include <stdio.h>
#include <assert.h>
#include <sys/stat.h>
#include <time.h>

#include "header.h"

int main(int argc, char *argv[])
{
    FILE* output_file = fopen(DUMP_FILE, "w");

    CheckFile(output_file);

    struct stat file_inf = {0};

    if (stat(argv[1], &file_inf) == -1)
    {
        fprintf(stderr, "Error in file\n");
        return 0;
    }

    fprintf(output_file, "File name: %s\n\n", argv[1]);

    if (define_type(&file_inf, output_file) == TYPE_NOT_EXIST)
    {
        fprintf(stderr, "<<<Type of the file is not exist in stat lib!>>>\n");
    }

    printf_file_information(&file_inf, output_file);

    CheckFclose(output_file);

    return 0;
}

ret_consts define_type (struct stat* file_inf, FILE* file_ptr)
{
    assert(file_inf);

    _DEF_TYPE_(S_ISBLK,  "The type is block special file\n");
    _DEF_TYPE_(S_ISCHR,  "The type is character special file\n");
    _DEF_TYPE_(S_ISDIR,  "The type is directory\n");
    _DEF_TYPE_(S_ISFIFO, "The type is FIFO file\n");
    _DEF_TYPE_(S_ISLNK,  "The type is symbolic link\n");
    _DEF_TYPE_(S_ISREG,  "The type is ordinary file\n");
    _DEF_TYPE_(S_ISSOCK, "The type is soket file\n");

    return TYPE_NOT_EXIST;
}

void printf_file_information(struct stat* file_inf, FILE* file_ptr)
{
    assert(file_inf);

    fprintf(file_ptr, "File bytes size: %ld\nLast open was:     %s"
           "Last modification: %sLast changes:      %s",
           file_inf->st_size, ctime(&file_inf->st_atime),
           ctime(&file_inf->st_mtime), ctime(&file_inf->st_ctime));
}

void CheckFclose(FILE* file_ptr)
{
    assert(file_ptr);

    int fclose_return = fclose(file_ptr);

    if (fclose_return != 0)
    {
        fprintf(stderr, "File closed wrong, fclose_return = %d\n", fclose_return);
    }
}

int CheckFile(FILE* file)
{
    if (file == NULL)
    {
        fprintf(stderr, "File not opened\n");
        return CHECK_FILE_ERROR;
    }

    return CHECK_FILE_OK;
}
