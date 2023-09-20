#include "main.h"
#include <stdio.h>

/**
 * _print - Implementation of own printf without formatting
 * @string: string to print
 * Return: Always 0 (Success)
 */
void _print(char * string)
{
	int counter = 0;
	char ch;

	if (string != NULL)
	{
		ch = string[counter];
		
		while (ch != '\0')
		{
			_putchar(ch);
			counter++;
			ch = string[counter];
		}
	}
	else
	{
		_print("(null)");
	}	
}
