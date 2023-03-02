#include "main.h"

/**
 * puts-half - prints half of a string
 * @str: The string to print
 * Return: void
 */
void puts_half(char *str)
{
int len = 0;
while (*str != '\0')
{
len++;
str++;
}
str -= (len / 2);
while (*str != '\0')
{
_putchar(*str);
str++;
}
_putchar('\n');
}
