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
char *cmd;
struct stat st;
token = strtok(path, ":");
while (token)
{
cmd = malloc(strlen(token) + strlen(command) + 3);
if (cmd == NULL)
{
perror("malloc");
exit(EXIT_FAILURE);
}
strcpy(cmd, token);
strcat(cmd, "/");
strcat(cmd, command);
if (stat(cmd, &st) == 0)
return (cmd);
free(cmd);
token = strtok(NULL, ":");
}
return (NULL);
}
