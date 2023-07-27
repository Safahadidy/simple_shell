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
#endif
