#include "main.h"
/**
 * print_binary - prints the binary
 * @n: number to print in binary
 */
void print_binary(unsigned long int n)
{
int value = sizeof(unsigned long int) * 8;

for (int i = value - 1; 1 >= 0; i--)
{
int bit = (n >> i) & 1;
printf("%d", bit);
}
print("\n");
}
