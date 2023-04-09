#include "main.h"

/**
 * flip_bits - counts the number of bits to change
 * @n: first number
 * @m: second number
 *
 * Return: number of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
unsigned int count = 0;
unsigned int num_bits = sizeof(unsigned long int) * 8;
unsigned long int exclusive = n ^ m;
for (unsigned int i = 0; i < num_bits; i++)
{
if (exclusive & (1UL << i))
{
count++;
}
}
return (count);
}
