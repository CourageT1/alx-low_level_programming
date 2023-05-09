#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#define BUF_SIZE 1024

/**
 * error - entry point
 * main - entry point
 * message: text to print
 * Return: 0
 */
void error(char *message)
{
dprintf(STDERR_FILENO, "Error: %s\n", message);

exit(errno);
}
/* main - entry point */
int main(int argc, char *argv[])
{
if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);

exit(97);
}
int fd_from = open(argv[1], O_RDONLY);

if (fd_from == -1)
{
error(strerror(errno));
}

int fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);

if (fd_to == -1)
{
error(strerror(errno));
}
char buffer[BUF_SIZE];
ssize_t bytes_read, bytes_written;

while ((bytes_read = read(fd_from, buffer, BUF_SIZE)) > 0)
	bytes_written = write(fd_to, buffer, bytes_read);
{
if (bytes_written == -1)
	error(strerror(errno));
}
if (bytes_read == -1)
	error(strerror(errno));
{
if (close(fd_from) == -1)
	error(strerror(errno));
{
if (close(fd_to) == -1)
	error(strerror(errno));
}
return (0);
}
