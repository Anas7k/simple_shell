#ifndef _SHELL_H
#define _SHELL_H
#endif

int _putchar(int c);
void _print(char * string);
int len(char * string);
char ** split(char * string, char * sep, int max_splits);
char * add(char * a , char * b);
int isfile(const char * filepath);
int isdir(char * path);
int array_len(char ** array);
int int_array_len(int * array);
char * substring(const char * string_array ,int start_index ,int end_index);
int cmp(char * a, char * b);
void array_print(char ** arr, char * sep);