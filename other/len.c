#include <stdio.h>

/**
* len - get length of a string
* @string: chosen string
* Return: Length of string
*/
int len(char * string)
{
	int counter = 0;
	char ch;
	
	ch = string[counter];
	
	while (ch != '\0')
	{
		counter++;
		ch = string[counter];
	}
	return (counter);
	
}

/**
* array_len - counts number of items in an array
* @array: Array with items
* Return: Number of items in an Array
*/
int array_len(char ** array)
{
	int counter = 0;
	char * string;
	
	string = array[counter];
	
	while (string)
	{
		counter++;
		string = array[counter];
	}
	return (counter);
	
}

/**
* int_array_len - counts number of items in an array
* @array: Array with items
* Return: Number of items in an Array
*/
int int_array_len(int * array)
{
	int counter = 0;
	int nm;
	
	nm = array[counter];
	
	while (nm != '\0')
	{
		counter++;
		nm = array[counter];
	}
	return (counter);
	
}
