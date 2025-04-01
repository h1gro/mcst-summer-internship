#ifndef _STAT_
#define _STAT_

#define _DEF_TYPE_(_MACR_NAME_, MESSAGE) \
{                                        \
if (_MACR_NAME_(file_inf->st_mode))      \
{                                        \
    fprintf(file_ptr, MESSAGE);          \
    return TYPE_EXIST;                   \
}                                        \
}while(0);

const char* DUMP_FILE = "information.txt";

enum ret_consts
{
    TYPE_EXIST     = 0,
    TYPE_NOT_EXIST = 1,
};

enum check_file_consts
{
    CHECK_FILE_ERROR = 1,
    CHECK_FILE_OK    = 0,
};

ret_consts define_type       (struct stat* file_inf, FILE* file_ptr);

void printf_file_information (struct stat* file_inf, FILE* file_ptr);
void CheckFclose             (FILE* file_ptr);

int CheckFile                (FILE* file);

#endif
