#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <assert.h>
#include "main.h"

/**
 * substring - build substring from a string
 * @string_array: array of characters ,ie string
 * @start_index: index to start from ,from the array
 * @end_index: index to to end to ,from the array
 * end_index is custom last character index within the array
 * Return: Array of splitted strings
 */
char *substring(const char *string_array, int start_index, int end_index)
{
    int ln, i;
    int str_len = len((char *)string_array);
    char *st;

    ln = end_index - start_index;
    st = malloc(sizeof(char) * (ln + 2)); /* including null byte */

    if (st == NULL)
    {
        /*_print("\n[ERROR]: Failed to allocated mem for function build_string\n");*/
        return (NULL);
    }

    if ((str_len < ln) || (start_index > str_len - 1) || (end_index > str_len - 1) || (ln < 1))
    {
        /*_print("\n[ERROR]: String passed to build string has doesnt match with start_index and end_index parameters\n");*/
        return (NULL);
    }

    for (i = 0; start_index <= end_index; (start_index++, i++))
    {
        st[i] = string_array[start_index];
    }

    st[i] = '\0'; /* ending the string */

    return (st);
}

/**
 * split - split a string
 * @string: string to be splitted
 * @sep: separator to split with
 * Return: Array of splitted strings
 */
char **split(char *string, char *sep, int max_splits)
{
    char **splitted;
    char *s;
    char iter_char;
    int i, j;
    int counter;
    int current_splits; /* number of splitted strings so far */
    int *match_indexes; /* indexes at certain match of <sep> ie index of first character of <sep> in string*/
    int mem_allocated;
    int sep_match;
    int mx_splits;
    int index_before, index_after;

    counter = 0;
    current_splits = 0;
    iter_char = string[counter];
    mem_allocated = false;
    sep_match = true; /* true by default */
    mx_splits = max_splits;

    while (true)
    {
        iter_char = string[counter];

        if (mx_splits)
        {
            /* if max splits was given */
            if (current_splits == mx_splits)
            {
                break; /* max splits are reached */
            }

            if (!mem_allocated)
            {
                /**
                 *  only allocate mem if not allocated
                 * this applies only if max_splits is set
                 */
                splitted = malloc(sizeof(char *) * (mx_splits + 2));
                match_indexes = malloc(sizeof(char *) * (mx_splits + 2));
                mem_allocated = true;
            }

            if ((splitted == NULL) || (match_indexes == NULL))
            {
                _print("\n[ERROR]: Failed to allocate mem for split\n");
                return (NULL);
            }

            /* memory is already allocated */
            /* setting i to 0 meaning starting a new sep match check */
            i = 0;

            if (iter_char == sep[i])
            {
                /**
                 * running tests to check if really this is true
                 * first character of <sep> matches this <iter_char>
                 */
                sep_match = true;

                for (; i < len(sep); i++)
                {
                    /**
                     * starting checking if the we found a <sep>
                     */
                    if (sep[i] != string[counter + i])
                    {
                        sep_match = false;
                    }
                }

                /* if separator match is found */
                if (sep_match)
                {
                    /* we add index when we found <sep> first character in the string */
                    match_indexes[current_splits] = counter;
                    current_splits += 1;
                    counter += len(sep) - 1;

                    /**
                     *  skip counter +(length of <sep> - 1)
                     * counter will be added +1 in advance by the code on bottom of loop
                     * so instead of adding (length of <sep>) to counter to skip
                     * to next char after <sep> ;we reduce by 1*/
                }
            }
        }
        else
        {
            _print("\n[ERROR]: Please provide a positive integer on max_splits\n");
        }
        counter++;
    }
    /* closing match indexes array */
    match_indexes[current_splits] = '\0';

    splitted[0] = "hello";
    splitted[1] = '\0';

    i = 0;

    while (true)
    {
        j = match_indexes[i];

        if (j == '\0')
        {
            break;
        }

        if (i == 0)
        {
            index_before = 0;
            index_after = j - 1;
        }

        else if (j < current_splits - 1)
        {
            /* last index in match_indexes is still less than the last index of string */
            index_before = j;
            index_after = current_splits - 1;
        }

        else
        {
            index_before = match_indexes[(i - 1)] + len(sep);
            index_after = j - 1;
        }

        s = substring(string, index_before, index_after);
        splitted[i] = s;
        i += 1;
    }

    if (i == 0)
    {
        /* nothing to split */
        splitted[i] = string;
        i += 1;
    }

    splitted[i] = '\0';
    free(match_indexes);

    return (splitted);
}
