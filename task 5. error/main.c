#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#include "header.h"

int main()
{
    int open_ret = open("sdbhd", O_RDONLY); //try open unexist file by func open();

    if (errno) //errno check
    {
        printf("meaning of errno = %d\n\n<strerror> : %s\n", errno, strerror(errno));  //errno - number of error
        perror("<perror>   ");               //perror - func that take errno number and printf string of error
    }

    return 0;
}
