#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 1024
void print_error(int code, const char *message)
{
dprintf(STDERR_FILENO, "Error: %s\n", message);
exit(code);
void copy_file(const char *file_from, const char *file_to)
{
int fd_from, fd_to;
char buffer[BUFFER_SIZE];
ssize_t bytes_read, bytes_written;
fd_from = open(file_from, O_RDONLY);
if (fd_from == -1)
	print_error(98, strerror(errno));
}
fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
if (fd_to == -1)
	print_error(99, strerror(errno));
while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
bytes_written = write(fd_to, buffer, bytes_read);
if (bytes_written == -1)
	print_error(99, strerror(errno));
{
if (bytes_read == -1)
	print_error(98, strerror(errno));
}
if (close(fd_from) == -1)
	print_error(100, strerror(errno));
{
if (close(fd_to) == -1)
	print_error(100, strerror(errno));
}
int main(int argc, char *argv[])
{
if (argc != 3)
	dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
exit(97);
}
copy_file(argv[1], argv[2]);
return (0);
}
