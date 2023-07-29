#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>
char **splitter(char *str);
char *get_command(char *command);
char *get_env_var(char *env_var);
extern char **environ;
int set_env_var(char *name, char *value, int overwrite);
ssize_t _getline(char **buffer, size_t *size, FILE *_stdin);
char *read_input_interactive(char **buffer);
int _putchar(char c);
void _puts(char *str);
void sig_handler(int signal);
void handle_env_commands(char **tokens);
#endif
