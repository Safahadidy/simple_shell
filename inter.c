#include "shell.h"
/**
 * read_input_interactive - function that read and store any instruction
 * @buffer: the adress where instruction is stored (buffer)
 * @size: size of instruction
 * Return: pointer to buffer where information is stored
 */
char *read_input_interactive(char **buffer)
{
char *data = NULL;
size_t size = 0;
ssize_t n_line = _getline(&data, &size, stdin);
if (n_line == -1)
{
free(data);
*buffer = NULL;
exit(1);
}
if (n_line == EOF)
{
_puts("\n");
free(data);
exit(EXIT_SUCCESS);
}
*buffer = data;
return (data);
}
