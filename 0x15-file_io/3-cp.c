#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <fcntl.h>

#include <errno.h>

#include <string.h>

#define BUF_SIZE 1024

/**

 * error - prints an error message and exits the program

 * @message: the error message to print

 *

 * Return: None

 */

void error(char *message);

/**

 * main - copies the contents of one file to another

 * @argc: the number of arguments supplied to the program

 * @argv: an array of pointers to the arguments

 *

 * Return: 0 on success, 97 on incorrect usage, or an error code on failure

 */

int main(int argc, char *argv[])

{

    int fd_from, fd_to;

    ssize_t nread, nwritten;

    char buf[BUF_SIZE];

    if (argc != 3)

    {

        dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);

        return (97);

    }

    fd_from = open(argv[1], O_RDONLY);

    if (fd_from == -1)

    {

        error(strerror(errno));

    }

    fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd_to == -1)

    {

        error(strerror(errno));

    }

    while ((nread = read(fd_from, buf, BUF_SIZE)) > 0)

    {

        nwritten = write(fd_to, buf, nread);

        if (nwritten == -1)

        {

            error(strerror(errno));

        }

    }

    if (nread == -1)

    {

        error(strerror(errno));

    }

    if (close(fd_from) == -1)

    {

        error(strerror(errno));

    }

    if (close(fd_to) == -1)

    {

        error(strerror(errno));

    }

    return (0);

}

/**

 * error - prints an error message and exits the program

 * @message: the error message to print

 *

 * Return: None

 */

void error(char *message)

{

    dprintf(STDERR_FILENO, "Error: %s\n", message);

    exit(errno);

}

