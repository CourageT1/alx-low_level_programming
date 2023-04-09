#include "main.h"

/**
 * clear_bit - sets the value
 * @n: pointer to the number to change
 * @index: bit to clear
 * Return: 1 (success), -1 (failure)
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
if (index > 63)
	return (-1);
*n &= ~(1UL << index);
return (1);
}
