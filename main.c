#include "strsort.h"
#include <sys/stat.h>

int main(int argc, char* argv[])
{
    struct stat unsort_inf = {0};
    struct file_t files    = {0};

    ReadArgs(&files, &unsort_inf, argc, argv);

    FilesProcessing(&files, unsort_inf.st_size);

    DefineComp(&files, argv[3]);

    SortText(&files);

    PrintBuffer(&files);

    Dtor(&files);
    return 0;
}
