#include "shell.h"
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
tokens[i++] = token;
token = strtok(NULL, " \t\n");
}
for (i = 0; tokens[i]; i++)
printf("%s\n", tokens[i]);
return (tokens);
}
