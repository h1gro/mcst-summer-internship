#ifndef _PARAL_PROC_
#define _PARAL_PROC_

const char* PARENT_FILE = "parent.txt";
const char* CHILD_FILE  = "child.txt";

void DoParent (FILE* read_file);
void DoChild  (FILE* read_file);

#endif
