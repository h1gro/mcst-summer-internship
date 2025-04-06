#include "strsort.h"

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

void DefineComp(struct file_t* files, const char* comparator)
{
    assert(files);

    if (!strcmp(comparator, "length_up"))
    {
        files->comparator = cmp_length_up;
    }

    else if (!strcmp(comparator, "length_down"))
    {
        files->comparator = cmp_length_down;
    }

    else
    {
        perror("Comparator did't exist!\n");
        Dtor(files);
        exit(0);
    }
}

int cmp_length_up(const void* str1, const void* str2)
{
    return strlen(*(const char**) str1) - strlen(*(const char**) str2);
}

int cmp_length_down(const void* str1, const void* str2)
{
    return  (-1) * (strlen(*(const char**) str1) - strlen(*(const char**) str2));
}

void SortText(struct file_t* files)
{
    qsort(files->addr, files->num_lines, sizeof(char*), files->comparator);
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
        if (files->text[i] == '\0')
        {
            files->addr[n] = &files->text[i + 2];
            n++;
        }
    }
}

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

    stat(file_for_sort, unsort_inf);
}

void PrintBuffer(struct file_t* files)
{
    assert(files);

    for (int i = 0; i < files->num_lines; i++)
    {
        fprintf(files->sort, "%s\n", files->addr[i]);
    }
}

void Dtor(struct file_t* files)
{
    assert(files);

    free(files->text);
    free(files->addr);

    fclose(files->sort);
    fclose(files->unsort);
}
