#ifndef _PARAL_PROC_
#define _PARAL_PROC_

//macro for checking return value of fread/fwrite
//but it might be a function
#define _WR_RETURN_(FUNC, ERROR)                  \
{                                                 \
if (FUNC != read_file_size)                       \
{                                                 \
    printf("something going wrong with file\n");  \
    free(interim_buf);                            \
                                                  \
    return ERROR;                                 \
}                                                 \
}while(0);

//constant names of the files
static const char* PARENT_FILE = "parent.txt";
static const char* CHILD_FILE  = "child.txt";

//fread/fwrite return varyables
enum wr_ret
{
    FREAD_ERROR  = -153,
    FWRITE_ERROR = 153,
    SUCCESS      = 351
};

enum check_file_consts
{
    CHECK_FILE_ERROR = 1,
    CHECK_FILE_OK    = 0,
};

FILE* DoParent (FILE* read_file, size_t read_file_size);

void CheckFclose     (FILE* file_ptr);
void DoChild         (FILE* read_file, size_t read_file_size);
void ResultProcesses (FILE* include_file, size_t read_file_size);
void ProcBranching   (FILE* read_file, struct stat* file_inf);

int FileCopy  (FILE* read_file, FILE* write_file, size_t read_file_size);
int CheckFile (FILE* file);
#endif
