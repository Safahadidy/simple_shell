#include "shell.h"
/**
 * main - checks the code.
 * @ac: the numbers of the argv.
 * @av: the strings entered to the file.
 * @env: controls the environment.
 * Return: always 0.
 */

int main(int ac, char **av, char **env)
{
char *buffer = NULL, *cmd, *read;
int token_size = 0;
size_t size = 0;
int status;
pid_t pid;
signal(SIGINT, sig_handler);
while (1)
{
if (isatty(STDIN_FILENO))
{
write(1, "$ ", 2);
read = read_input_interactive(&buffer, &size);
}
else
{
read = read_input_noninteractive(&buffer, &size);
}
strcpy(command, read);
char **tokens = splitter(command);
if (strcmp(tokens[0], "exit") == 0)
exit(0);
else if (strcmp(tokens[0], "setenv") == 0 || strcmp(tokens[0], "getenv") == 0)
{
handle_env_commands(tokens);
}
pid = fork();
if (pid == 0)
{
cmd = get_command(tokens[0]);
if (cmd)
execve(cmd, tokens, env);
printf("Command not found\n");
exit(0);
}
wait(&status);
}
free(read);
free(tokens);
return (0);
}
