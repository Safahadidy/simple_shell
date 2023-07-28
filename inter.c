#include "shell.h"
/**
 * read_input_interactive - function that read and store any instruction
 * @buffer: the adress where instruction is stored (buffer)
 * @size: size of instruction
 * Return: pointer to buffer where information is stored
 */
char *read_input_interactive(char **buffer, size_t *size)
{
char *data;
n_read = getline(data, size, stdin);
if (n_read == '\0')
{
free(*buffer);
exit(1);
}
if (n_read == EOF)
{
_puts("\n");
free(*buffer);
exit(EXIT_SUCCESS);
}
return (data);
}
