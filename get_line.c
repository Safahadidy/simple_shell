#include "shell.h"
/**
 * _getline - function that read and store any instruction
 * @_stdin :input
 * @buffer: the adress where instruction is stored (buffer)
 * @size: size of instruction
 * Return: -1 in error
 */
ssize_t _getline(char **buffer, size_t *size, FILE *_stdin)
{
return (getline(buffer, size, _stdin));
}
