#include "main.c"
#include <stdlib.h>
/**
 * read_textfile - read text file print
 * @filename: textfile being read
 * @letters: number of letters to read
 * Return: w - actual number of bytes read, 0 otherwise
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
if (filename == NULL)
	return (0);
{
FILE *file = fopen(filename, "r");
if (file == NULL)
	return (0);
}
char *buffer = (char *) malloc(sizeof(char) (letters + 1))
if (buffer == NULL)
{
fclose(file);
return (0);
}
ssize_t bytesRead = fread(buffer, sizeof(char), letters, file);
if (bytesRead < 0)
{
fclose(file);
free(buffer);
return (0);
}
buffer[bytesRead] = '0';
printf("%s", buffer);

fclose(file);
free(buffer);

return (bytesRead);
}
