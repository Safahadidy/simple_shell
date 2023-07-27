#include "shell.h"
/**
 * get_command  - remove the leading space.
 * @command: the string.
 * Return: void.
 */
char *get_command(char *command)
{
char *path = (char *)getenv("PATH");
char *token;
char *cmd_full;
struct stat st;
token = strtok(path, ":");
while (token)
{
cmd_full = malloc(strlen(token) + strlen(command) + 2);
if (cmd_full == NULL)
{
perror("malloc");
exit(EXIT_FAILURE);
}
strcpy(cmd_full, token);
strcat(cmd_full, "/");
strcat(cmd_full, command);
if (stat(cmd_full, &st) == 0)
return (cmd_full);
free(cmd_full);
token = strtok(NULL, ":");
}
return (NULL);
}
