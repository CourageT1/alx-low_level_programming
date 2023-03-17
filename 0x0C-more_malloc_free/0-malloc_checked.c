#include "main.h"
#include <stdlib.h>

/**
 * malloc_checked - allocates memory using malloc
 * @b: number of bytes to allocate
 *
 * Return: pointer to allocated memory, if it fails, value is equal to 98
 */
void *malloc_checked(unsigned int b)
{
char *p;

p = malloc(b);
if (p == NULL)
	exit(98);
return (p);
}
