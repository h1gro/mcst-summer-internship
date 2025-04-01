#include <stdio.h>
#include <assert.h>
#include <sys/stat.h>

#include "header.h"

int main(int argc, char *argv[])
{

    struct stat file_inf = {0};

    if (stat(argv[1], &file_inf) == -1)
    {
        fprintf(stderr, "Error in file\n");
        return 0;
    }

    printf("File name: %s\n\n", argv[1]);

    if (define_type(&file_inf) == TYPE_NOT_EXIST)
    {
        fprintf(stderr, "<<<Type of the file is not exist in stat lib!>>>\n");
    }

    return 0;
}

ret_consts define_type (struct stat* file_inf)
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

