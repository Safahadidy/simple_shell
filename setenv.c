#include "shell.h"

/**
 * set_env_var - environment
 * @name: the string.
 * @value: the string.
 * @overwrite: the inreger.
 * Return: 0 to succes.
 */
int set_env_var(char *name, char *value, int overwrite)
{
int i = 0;
int len = strlen(name);
char *new_var = NULL;
while (environ[i])
{
if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
{
if (overwrite)
{
new_var = malloc(strlen(name) + strlen(value) + 2);
if (new_var == NULL)
{
perror("malloc");
exit(EXIT_FAILURE);
}
strcpy(new_var, name);
strcat(new_var, "=");
strcat(new_var, value);
environ[i] = new_var;
}
return (0);
}
i++;
}
new_var = malloc(strlen(name) + strlen(value) + 2);
if (new_var == NULL)
{
perror("malloc");
exit(EXIT_FAILURE);
}
strcpy(new_var, name);
strcat(new_var, "=");
strcat(new_var, value);
environ[i] = new_var;
environ[i + 1] = NULL;
return (0);
}
