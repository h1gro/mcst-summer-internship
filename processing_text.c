#include "strsort.h"
#include <sys/stat.h>

void ReadArgs(struct file_t* files, struct stat* unsort_inf, int argc, char* argv[])
{
    const char* file_for_sort = argv[1];
    const char* sorted_file   = argv[2];
    const char* comparator    = argv[3];

    if (argc != 4)
    {
        perror("more than 3 arguments of comand line\n");
    }

    files->unsort = fopen(file_for_sort, "r");
    files->sort   = fopen(sorted_file, "w");

    CheckFile(files->unsort);
    CheckFile(files->sort);

    stat(file_for_sort, unsort_inf);
}

void FilesProcessing(struct file_t* files, size_t size)
{
    assert(files);

    files->text = (char*) calloc(size, sizeof(char));
    assert(files->text);

    printf("num elems = %lu\n", fread(files->text, sizeof(char), size, files->unsort));

    CountLines(files, size);

    files->addr = (char**) calloc(files->num_lines, sizeof(char*));
    assert(files->addr);

    FillingAddr(files, size);
}

void CountLines(struct file_t* files, size_t size)
{
    assert(files);

    for (size_t i = 0; i < size; i++)
    {
        if (files->text[i] == '\r')
        {
            files->text[i] = '\0';
            files->num_lines++;
        }
    }
    printf("lines = %lu\n", files->num_lines);
}

void FillingAddr(struct file_t* files, size_t size)
{
    assert(files);

    files->addr[0] = &files->text[0];

    int n = 1;

    for (size_t i = 0; i < size - 2; i++)
    {
        printf("%s\n", &files->text[i]);
        if ((files->text[i] == '\0') && (!IfSpace(&(files->text[i]))))
        {
            files->addr[n] = &files->text[i + 2];
            n++;
        }
    }
}

void Dtor(struct file_t* files)
{
    assert(files);

    free(files->text);
    free(files->addr);

    CheckFclose(files->sort);
    CheckFclose(files->unsort);
}
