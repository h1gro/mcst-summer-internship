#include "strsort.h"
#include <sys/stat.h>

void ReadArgs(struct file_t* files, struct stat* unsort_inf, int argc, char* argv[])
{
    //get cmd line arguments
    const char* file_for_sort = argv[1]; //file that have to be sorted
    const char* sorted_file   = argv[2]; //file - ending sort version
    const char* comparator    = argv[3]; //name of comparator

    if (argc != 4) //check for only 4 argc: executable file, unsort file, sort file, name of comparator
    {
        perror("more than 3 arguments of comand line\n");
    }

    files->unsort = fopen(file_for_sort, "r");
    files->sort   = fopen(sorted_file, "w");

    //check opening files
    CheckFile(files->unsort);
    CheckFile(files->sort);

    //get file information
    stat(file_for_sort, unsort_inf);
}

void FilesProcessing(struct file_t* files, size_t size)
{
    assert(files);

    //allocate memory for copying content of the unsort file
    files->text = (char*) calloc(size, sizeof(char));
    assert(files->text);

    size_t fread_return = fread(files->text, sizeof(char), size, files->unsort);

    if (fread_return != size)
    {
        perror("something going wrong with file\n");
    }

    //count lines in text to know how many strings do we have
    CountLines(files, size);

    //allocate memory for array of addresses of strings from text
    files->addr = (char**) calloc(files->num_lines, sizeof(char*));
    assert(files->addr);

    //filling array of addr by reading '\0' at the end of every string
    FillingAddr(files, size);
}

void CountLines(struct file_t* files, size_t size)
{
    assert(files);

    for (size_t i = 0; i < size; i++)
    {
        if (files->text[i] == '\r') //if we reached the end of the string and read '\r' - replace it to '\0'
        {
            files->text[i] = '\0';
            files->num_lines++; //counter of lines
        }
    }
}

void FillingAddr(struct file_t* files, size_t size)
{
    assert(files);
    //init adr of the first string
    files->addr[0] = &files->text[0];

    int n = 1;

    for (size_t i = 0; i < size - 2; i++)
    {
        //get addr of str to array of addresses if it's not empty
        if ((files->text[i] == '\0') && (!IfSpace(&(files->text[i + 2]))))
        {
            files->addr[n] = &files->text[i + 2];
            n++;
        }
    }
    //num_lines might not match (cause of space lines)
    files->num_lines = n;
}

void Dtor(struct file_t* files)
{
    assert(files);

    //free up memory
    free(files->text);
    free(files->addr);

    //check closing files
    CheckFclose(files->sort);
    CheckFclose(files->unsort);
}
