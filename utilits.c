#include "strsort.h"

void CheckFclose(FILE* file_ptr)
{
    assert(file_ptr);

    int fclose_return = fclose(file_ptr);

    if (fclose_return != 0)
    {
        fprintf(stderr, "File closed wrong, fclose_return = %d\n", fclose_return);
    }
}

int CheckFile(FILE* file)
{
    if (file == NULL)
    {
        fprintf(stderr, "File not opened\n");
        return CHECK_FILE_ERROR;
    }

    return CHECK_FILE_OK;
}

void PrintBuffer(struct file_t* files)
{
    assert(files);

    for (int i = 0; i < files->num_lines; i++)
    {
        if (!IfSpace(files->addr[i]))
        {
            fprintf(files->sort, "%s\n", files->addr[i]);
        }
    }
}

int IfSpace(const char* string)
{
    int i = 0;

    while (string[i] != '\n')
    {
        if ((string[i] != ' '))
        {
            return 0;
        }
        i++;
    }

    return 1;
}
