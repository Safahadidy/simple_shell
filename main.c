#include "shell.h"
/**
 * main - checks the code.
 * Return: always 0.
 */
int main(void)
{
signal(SIGINT, sig_handler);
char *buffer;
buffer = NULL;
char **tokens;
char *read;
size_t size = 0;
char command[100];
int pid, status;
while (1)
{
if (isatty(STDIN_FILENO))
{
write(1, "$ ", 2);
read = read_input_interactive(&buffer);
}
else
{
ssize_t read_size = _getline(&buffer, &size, stdin);
if (read_size == -1)
exit(1);
read = buffer;
}
strcpy(command, read);
tokens = splitter(command);
if (strcmp(tokens[0], "exit") == 0)
exit(0);
else if (strcmp(tokens[0], "setenv") == 0 || strcmp(tokens[0], "getenv") == 0)
handle_env_commands(tokens);
pid = fork();
if (pid == 0)
{
char *cmd = get_command(tokens[0]);
if (cmd)
execve(cmd, tokens, NULL);
printf("Command not found\n");
exit(0);
}
wait(&status);
}
free(buffer);
return (0);
}
