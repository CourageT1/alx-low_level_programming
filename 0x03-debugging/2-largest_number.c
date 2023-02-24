#include "main.h"

/**
 * Largest_number - returns the largest of 3 numbers
 * @a: First integer
 * @b: Second integer
 * @c: third integer
 * Description: Fix the code so that it correctly prints out the largest of three numbers, no matter the case
 * Return: largest number
 */
int largest_number(int a, int b, int c)
{
int largest;
if (a > b && a > c)
{
largest = a;
}
else if (b > a && b > c)
{
largest = b;
}
else
{
largest = c;
}
return (largest);
}
