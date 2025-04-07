#include "strsort.h"
#include <sys/stat.h>

/*suppoted methods of sort: | Cmd of comparators:
1) length for up            |     light_up
2) length for down          |     light_down
3) alphabet                 |     alphabet
4) reverse alphabet         |     alphabet_reverse
*/

int main(int argc, char* argv[])
{
    struct stat unsort_inf = {0}; //init stat struct to get byte-size of the file
    struct file_t files    = {0};

    ReadArgs(&files, &unsort_inf, argc, argv);

    FilesProcessing(&files, unsort_inf.st_size); //process files (sort.txt and unsort.txt)

    //this function defined what comparator user wrote
    DefineComp(&files, argv[3]);

    SortText(&files); //qsort

    PrintBuffer(&files); //print sorted version of text in special file

    Dtor(&files); //free up memory and close files
    return 0;
}
