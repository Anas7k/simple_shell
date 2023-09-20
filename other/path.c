#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>
#include "main.h"

/**
 * isfile - checks whether a file exists or not
 * @filepath: Path to file
 * Return: 0 (if false) ; 1 (if true) ; Other int (unexpected error)
 */
int isfile(const char * filepath)
{
	int fd = open(filepath, O_RDWR);
	
	if (fd == -1)
	{
		if ((errno == EACCES) | (errno == EROFS))
		{
			/**
			* file exists but permission error
			* or readonly error
			*/
			return (1);
		}
		
		else if ((errno == ENOENT) | (errno == EISDIR))
		{
			/**
			* file doesnt exist or this is a directory
			*/
			return (0);
		}
		
		else 
		{
			/* unexpected error */
			return (errno);
		}
	}
	close(fd);
	return (1);
}

/**
 * isdir - checks whether a file exists or not
 * @path: Path to directory
 * Return: 0 (if false) ; 1 (if true) ; Other int (unexpected error)
 */
int isdir(char * path)
{
	DIR * dir = opendir(path);
	
	if (dir == NULL)
	{
		/**
		* further analysis why we cant open the dir
		* if only no such file or directory error ,
		* then we return 0 else 1 or printing error and returning errno
		*/
		if ((errno == EACCES))
		{
			/*directory exists but permission error*/
			return (1);
		}
		
		else if ((errno == ENOENT) | (errno == ENOTDIR))
		{
			/**
			* directory doesnt exist or this is not a
			* directory but a file
			*/
			return (0);
		}
		
		else 
		{
			/* unexpected error */
			return (errno);
		}
	}
	closedir(dir);
	return (1);
}
