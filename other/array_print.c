#include "main.h"
#include <stdio.h>

/**
 * array_print - print strings in an array
 * @arr: array with strings
 * Return: void
 */
void array_print(char ** arr, char * sep)
{
    int a;
    
    for(a = 0 ; a < array_len(arr) ; a++)
    {
        _print(arr[a]);
        if (sep)
        {
            _print(sep);
        }
    }
}