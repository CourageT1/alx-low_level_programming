#include<stdio.h>
#include<stdlib.h>
/**
 * main - Entry point
 *
 * Return: Always (Success)
 */
int main(void)
{
char i;
for (i = 'a' ; i <= 'z' ; i++)
if (i != 'q' && i != 'e')
putchar(i);
putchar('\n');
return (0);
}
