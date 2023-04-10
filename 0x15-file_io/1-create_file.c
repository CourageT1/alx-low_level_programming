#include "main.h"
#include <stdio.h>

/**
 * create_file - creates file
 * @filename: pointer to name of file to create
 * @text_content: pointer to string to write to file
 * Return: --1 (failure), -1 (otherwise)
 */
int create_file(const char *filename, char *text_content)
{
if (filename == NULL)
	return (-1);
{
int fd = open(filenames, 0_WRONLY | 0_CREAT | 0_TRUNIC, S_IRUSR | S_LWUSR);
if (fd == -1)
	return (-1);
}
if (text_content != NULL)
ssize_t bytes_written = write(fd, text_content, strlen(text_content));
if (bytes_written == -1)
close(fd);
return (-1);

close(fd);
return (1);
}
