#include "main.h"

/**
 * binary_to_unit - converts a binary number
 * @b: string containing the number
 *
 * Return: converted number
 */
unsigned int binary_to_uint(const char *b)
{
if (!b)
return (0);
}
int i;
unsigned int value = 0;

while (b[i] != '\0')
{
if (b[i] != '0' && b[i] != '1')
	return (0);
}
value = value << 1;
if (b[i] == '1')
value = value | 1;
{
i++;
return (value);
}
