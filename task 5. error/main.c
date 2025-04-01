#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#include "header.h"

int main()
{
    int open_ret = open("sdbhd", O_RDONLY);

    if (errno)
    {
        printf("errno = %d\n", errno);
    }

    return 0;
}
