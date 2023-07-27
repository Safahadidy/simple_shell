#include "shell.h"

/**
 * handle_env_commands - handle the hash for non interactive mode.
 * @tokens: a string.
 * Return: void.
 */
void handle_env_commands(char **tokens)
{
if (strcmp(tokens[0], "setenv") == 0)
{
if (!tokens[1] || !tokens[2])
{
printf("Usage: setenv VAR VALUE\n");
}
else
{
set_env_var(tokens[1], tokens[2], 1);
}
}
else if (strcmp(tokens[0], "getenv") == 0)
{
if (tokens[1] == NULL)
{
printf("Usage: getenv VAR\n");
}
else
{
char *value = get_env_var(tokens[1]);
if (value)
printf("%s\n", value);
}
}
}
