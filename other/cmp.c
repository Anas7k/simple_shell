#include "main.h"
#include <stdbool.h>

/**
 * cmp - compare 2 strings
 * @a: first string
 * @b: second string
 * Return: 0 or 1 
 */
int cmp(char * a, char * b)
{
    int is_equal = true;
    int i = 0;
    int a_len = len(a);
    char char_a, char_b;

    for (; i < a_len ; i++)
    {
        char_a = a[i];
        char_b = b[i];
        if (char_a != char_b)
        {
            is_equal = false;
            break;
        } 
    }

    return (is_equal);
}
