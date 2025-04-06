#include "strsort.h"
#include <ctype.h>

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

    else if (!strcmp(comparator, "alphabet"))
    {
        files->comparator = cmp_alphabet;
    }

    else
    {
        perror("Comparator did't exist!\n");
        Dtor(files);
        exit(0);
    }
}

void SortText(struct file_t* files)
{
    qsort(files->addr, files->num_lines, sizeof(char*), files->comparator);
}

int cmp_alphabet(const void* str1, const void* str2)
{
    assert(str1);
    assert(str2);

    const char *string1 = *(const char**) str1;
    const char *string2 = *(const char**) str2;

    assert(string1);
    assert(string2);

    while ((*string1) && (*string2))
    {
        if ((isalpha(*string1)) && (isalpha(*string2)))
        {
            if (tolower(*string1) != tolower(*string2))
            {
                return tolower(*string1) - tolower(*string2);
            }
        }
        string1++;
        string2++;
    }

    return 0;
}

int cmp_length_up(const void* str1, const void* str2)
{
    return strlen(*(const char**) str1) - strlen(*(const char**) str2);
}

int cmp_length_down(const void* str1, const void* str2)
{
    return  (-1) * (strlen(*(const char**) str1) - strlen(*(const char**) str2));
}
