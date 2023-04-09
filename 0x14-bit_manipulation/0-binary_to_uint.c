#include "main.h"

/**
 * binary_to_uint - converts a binary number
 * @b: string containing the number
 *
 * Return: converted number
 */
unsigned int binary_to_uint(const char *b)
{
int i = 0;
unsigned int value = 0;

if (!b)
return (0);
while (b[i] != '\0')
{
value = value << 1;
if (b[i] == 1)
value = value | 1;
else if (b[i] != '0')
return (0);
i++;
}
return (value);
}
