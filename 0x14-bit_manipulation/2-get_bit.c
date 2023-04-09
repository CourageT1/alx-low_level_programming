#include "main.h"
#include <stdio.h>
/**
 * get_bit - returns the value of a bit
 * @n: number to search
 * @index: index of the bit
 * Return: value of the bit
 */
int get_bit(unsigned long int n, unsigned int index)
{
int bit_value;

if (index >= sizeof(unsigned long int) * 8)
fprintf(stderr, "Error: index out of reach.\n");
return (-1);

bit_value = (n >> index) & 1;
return (bit_value);
}
