#ifndef MAIN_H
#define MAIN_H

int _putchar(char c);
char *argstostr(int ac, char **av);
void free_grid(int **grid, int height);
int **alloc_grid(int width, int height);
