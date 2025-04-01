#ifndef _STAT_
#define _STAT_

//macros for defining st_mode file
#define _DEF_TYPE_(_MACR_NAME_, MESSAGE) \
{                                        \
if (_MACR_NAME_(file_inf->st_mode))      \
{                                        \
    printf(MESSAGE);                     \
    return TYPE_EXIST;                   \
}                                        \
}while(0); //while(0); - need for writing symbol ';' at the end of macroline

//consts for func define_type(...)
enum ret_consts
{
    TYPE_EXIST     = 0,
    TYPE_NOT_EXIST = 1,
};

ret_consts define_type       (struct stat* file_inf);

void printf_file_information (struct stat* file_inf);

#endif
