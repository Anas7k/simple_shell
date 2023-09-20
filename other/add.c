#include <stdlib.h>
#include "main.h"

/**
* add - Add two strings
* @a: first string
* @b: second string
* Return: Concatenated strings
*/
char * add(char * a , char * b)
{
	int a_len = len(a);
	int b_len = len(b);
	int counter = 0;
	int i = 0, j = 0;
	int t = (a_len + b_len) * sizeof(char) + sizeof(char);
	char char_a, char_b;
	char * newstr = malloc(t + sizeof(char));
	
	/* adding a to newstr first */
	char_a = a[i];
	while (char_a != '\0')
	{
		newstr[counter] = char_a;
		counter++;
		i++;
		char_a = a[i];
	}
	
	/* adding b to newstr */
	char_b = b[j];
	while (char_b != '\0')
	{
		newstr[counter] = char_b;
		counter++;
		j++;
		char_b = b[j];
	}
	
	/* closing the string */
	newstr[counter] = '\0';
	return (newstr);
}
