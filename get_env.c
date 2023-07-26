#include "shell.h"
/**
 * get_env_var - environment
 * @env_var: the string.
 * Return: void.
 */
char *get_env_var(char *env_var)
{
int i = 0;
char *key = NULL;
while (environ[i])
{
key = strtok(environ[i], "=");
if (strcmp(env_var, key) == 0)
return (strtok(NULL, "\n"));
i++;
}
return (NULL);
}
