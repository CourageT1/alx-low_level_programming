#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * append_text_to_file - appends text at end of file
 * @filename: a pointer to the name of file
 * @text_content: the string to add to end of file
 * Return: --1 (failure), -1 (if file doesnt exist)
 */
int append_text_to_file(const char *filename, char *text_content)
{
if (filename == NULL)
	return (-1);
{
if (text_content == NULL)
	return (1);
{
FILE *file = fopen(filename, "a");
if (file == NULL)
	return (-1);
}
}
fprintf(file, "%s", text_content);
fclose(file);
return (1);
}
