#include "shell.h"
/**
 * read_input_interactive - function that read and store any instruction
 * @buffer: the adress where instruction is stored (buffer)
 * @size: size of instruction
 * Return: pointer to buffer where information is stored
 */
char *read_input_interactive(char **buffer, size_t *size)
{
char *data = NULL;
ssize_t n_read = getline(&data, size, stdin);
if (n_read == -1)
{
free(data);
*buffer = NULL;
exit(1);
}
if (n_read == EOF)
{
_puts("\n");
free(data);
exit(EXIT_SUCCESS);
}
*buffer = data;
return (data);
}
