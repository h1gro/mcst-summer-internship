#ifndef _STR_SORT_
#define _STR_SORT_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct file_t
{
    FILE*  sort;                                 ////pointer on file with sorted text (where must be sorted text)
    FILE*  unsort;                               //pointer on file with unsorted text
    char*  text;                                 //array of the unsorted text
    char** addr;                                 //array of strings adr
    size_t num_lines;                            //counter of lines
    int (*comparator)(const void*, const void*); //name of func comparator
};

//consts for errors of checking file
enum check_file_consts
{
    CHECK_FILE_ERROR = 1,
    CHECK_FILE_OK    = 0,
};

//comparators
int CmpLengthUP        (const void* str1, const void* str2);
int CmpLengthDown      (const void* str1, const void* str2);
int CmpAlphabet        (const void* str1, const void* str2);
int CmpAlphabetReverse (const void* str1, const void* str2);
//--------------------
int CheckFile       (FILE* file);
int IfSpace         (const char* string);

void CheckFclose     (FILE* file_ptr);
void Dtor            (struct file_t* files);
void SortText        (struct file_t* files);
void PrintBuffer     (struct file_t* files);
void CountLines      (struct file_t* files, size_t size);
void FillingAddr     (struct file_t* files, size_t size);
void FilesProcessing (struct file_t* files, size_t size);
void DefineComp      (struct file_t* files, const char* comparator);
void ReadArgs        (struct file_t* files, struct stat* unsort_inf, int argc, char* argv[]);

#endif
