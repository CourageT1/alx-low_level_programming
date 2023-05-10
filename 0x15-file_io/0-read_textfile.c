#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * read_textfile - reads text file and writes it to standard output
 * @filename: name of the text file to read
 * @letters: maximum number of letters to read
 *
 * Return: number of bytes read and printed, or 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
int fd, bytes_read, bytes_written;
char *buffer;

if (filename == NULL)
	return (0);

fd = open(filename, O_RDONLY);

if (fd == -1)
	return (0);

buffer = malloc(sizeof(char) * letters);

if (buffer == NULL)
	return (0);

bytes_read = read(fd, buffer, letters);

if (bytes_read == -1)
{
free(buffer);

close(fd);
return (0);
}
bytes_written = write(STDOUT_FILENO, buffer, bytes_read);

if (bytes_written == -1 || bytes_written != bytes_read)
{
free(buffer);

close(fd);
return (0);
}
free(buffer);

close(fd);
return (bytes_written);
}
