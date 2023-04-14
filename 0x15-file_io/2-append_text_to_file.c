#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * append_text_to_file - appends text at end of file
 * @filename: a pointer to the name of the file
 * @text_content: string to add to end of file
 * Return: --1(failure), -1(if file does not exist)
 */
int append_text_to_file(const char *filename, char *text_content)
{
FILE *file = fopen(filename, "a");

if (filename == NULL)
	return (-1);

if (text_content == NULL)
	return (1);
{
if (file == NULL)
	return (-1);
}
fprintf(file, "%s", text_content);
fclose(file);
return (1);
}
