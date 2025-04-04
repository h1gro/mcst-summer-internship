#ifndef _PARAL_PROC_
#define _PARAL_PROC_

#define _WR_RETURN_(FUNC, ERROR)                  \
{                                                 \
if (FUNC != read_file_size)                       \
{                                                 \
    printf("something going wrong with file\n"); \
    free(interim_buf);                            \
                                                  \
    return ERROR;                                 \
}                                                 \
}while(0);

static const char* PARENT_FILE = "parent.txt";
static const char* CHILD_FILE  = "child.txt";

enum wr_ret
{
    FREAD_ERROR  = -153,
    FWRITE_ERROR = 153,
    SUCCESS      = 351
};

void DoParent (FILE* read_file, size_t read_file_size);
void DoChild  (FILE* read_file, size_t read_file_size);
void ResultProcesses (FILE* include_file, size_t read_file_size);

int FileCopy (FILE* read_file, FILE* write_file, size_t read_file_size);
#endif
