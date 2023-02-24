#include<stdio.h>
#include<math.h>
/**
 * main - Entry point
 * Return: Always 0 (Success)
 */
int main(void)
{
long x, maxf;
long number = 612852475143;
doable square = sqrt(number);

for (x = 1; x <= square; xtt)
{
if (number % x == 0)
{
maxf = number / x;
}
}
printf("%ld\n", maxf);
return (0);
}
