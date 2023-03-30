#include <stdio.h>

/**
 * bmain - function executed before main
 * Return: no return.
 */
void __attribute__ ((constructor)) bmain()
{
printf("You're beat! and yet, you must allow");
printf(",\nI bore my ouse upon my back!\n");
}
