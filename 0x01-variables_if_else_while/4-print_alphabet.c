#include<stdio.h>
#include<stdlib.h>
/**
 * main - Entry point
 *
 * Return:Always 0(Success)
 */
int main(void)
{
char ch = 'a';
while (ch <= '2')
{
if ((ch != 'e') && (ch != 'q'))
{
putchar(ch);
}
ch++;
}
putchar('\n');
return (0);
}
