#ifndef _STAT_
#define _STAT_

#define _DEF_TYPE_(_MACR_NAME_, MESSAGE) \
{                                        \
if (_MACR_NAME_(file_inf->st_mode))      \
{                                        \
    printf(MESSAGE);                     \
    return TYPE_EXIST;                   \
}                                        \
}while(0);

enum ret_consts
{
    TYPE_EXIST     = 0,
    TYPE_NOT_EXIST = 1,
};

ret_consts define_type       (struct stat* file_inf);

#endif
