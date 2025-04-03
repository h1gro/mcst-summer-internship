#ifndef _PARAL_PROC_
#define _PARAL_PROC_

const char* PARENT_FILE = "parent.txt";
const char* CHILD_FILE  = "child.txt";

void DoParent (FILE* read_file, size_t read_file_size);
void DoChild  (FILE* read_file, size_t read_file_size);
void FileCopy (FILE* read_file, FILE* write_file, size_t read_file_size);
#endif
