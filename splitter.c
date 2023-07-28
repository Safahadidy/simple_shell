#include "shell.h"
/**
 * splitter - function that read and store any instruction
 * @str: the string
 * Return: pointer to buffer where information is stored
 */
char **splitter(char *str)
{
char *token, **tokens = NULL;
int i = 0;
token = strtok(str, " \t\n");
while (token != NULL)
{
tokens = realloc(tokens, sizeof(char *) * (i + 1));
if (tokens == NULL)
{
perror("realloc");
exit(EXIT_FAILURE);
}
tokens[i] = strdup(token);
if (tokens[i] == NULL)
{
perror("strdup");
exit(EXIT_FAILURE);
}
i++;
token = strtok(NULL, " \t\n");
}
tokens = realloc(tokens, sizeof(char *) * (i + 1));
if (tokens == NULL)
{
perror("realloc");
exit(EXIT_FAILURE);
}
tokens[i] = NULL;
for (i = 0; tokens[i]; i++)
printf("%s\n", tokens[i]);
return (tokens);
}
