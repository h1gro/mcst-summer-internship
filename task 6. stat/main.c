#include <stdio.h>
#include <assert.h>
#include <sys/stat.h>
#include <time.h>

#include "header.h"

int main(int argc, char *argv[])
{
    struct stat file_inf = {0};  //init structure

    if (stat(argv[1], &file_inf) == -1) //check stat return for find error in file
    {
        fprintf(stderr, "Error in file\n");
        return 0;
    }

    printf("File name: %s\n\n", argv[1]); //printf file name, argv[1] = probfile.txt

    if (define_type(&file_inf) == TYPE_NOT_EXIST) //check return varyable from define_type
    {
        fprintf(stderr, "<<<Type of the file is not exist in stat lib!>>>\n");
    }

    printf_file_information(&file_inf); //func for print file parametres

    return 0;
}

ret_consts define_type (struct stat* file_inf)
{
    assert(file_inf);

    //define type of the file with help of standart macrosses
    _DEF_TYPE_(S_ISBLK,  "The type is block special file\n");
    _DEF_TYPE_(S_ISCHR,  "The type is character special file\n");
    _DEF_TYPE_(S_ISDIR,  "The type is directory\n");
    _DEF_TYPE_(S_ISFIFO, "The type is FIFO file\n");
    _DEF_TYPE_(S_ISLNK,  "The type is symbolic link\n");
    _DEF_TYPE_(S_ISREG,  "The type is ordinary file\n");
    _DEF_TYPE_(S_ISSOCK, "The type is soket file\n");

    return TYPE_NOT_EXIST;  //const for error type
}

void printf_file_information(struct stat* file_inf)
{
    assert(file_inf);

    //print file parametres
    printf("File bytes size: %ld\nLast open was: %s"
           "Last modification: %sLast changes: %s",
           file_inf->st_size, ctime(&file_inf->st_atime),
           ctime(&file_inf->st_mtime), ctime(&file_inf->st_ctime));
}
