#ifndef _STR_SORT_
#define _STR_SORT_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys/stat.h>

struct file_t
{
    FILE*  sort;
    FILE*  unsort;
    char*  text;
    char** addr;
    size_t num_lines;
    int (*comparator)(const void*, const void*);
};

// enum cmps
// {
//     CMP_LEN = "length";
// };

const char* FILE_FOR_SORT = "unsort.txt";
const char* SORTED_FILE   = "sort.txt";

int cmp_length_up   (const void* str1, const void* str2);
int cmp_length_down (const void* str1, const void* str2);

void Dtor            (struct file_t* files);
void SortText        (struct file_t* files);
void DefineComp      (struct file_t* files, const char* comparator);
void PrintBuffer     (struct file_t* files);
void CountLines      (struct file_t* files, size_t size);
void FillingAddr     (struct file_t* files, size_t size);
void FilesProcessing (struct file_t* files, size_t size);
void ReadArgs        (struct file_t* files, struct stat* unsort_inf, int argc, char* argv[]);

#endif
