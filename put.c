#include "shell.h"
/**
 * _puts -  prints a string
 * @str: string to print
 * Return: Nothing.
 */
void _puts(char *str)
{
int x;
for (x = 0; str[x] != '\0'; x++)
{
_putchar(str[x]);
}
}
