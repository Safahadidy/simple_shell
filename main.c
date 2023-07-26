#include "shell.h"
int main(int ac, char **av char **env)
{
	size_t len = 0;
	char *buffer = NULL, *cmd;
	int token_size = 0;
	size_t size = 0;
        int n_char = 0, status;
	pid_t pid;
        write(1,"$ ",2);
        n_char = getline(&buffer, &size, stdin);
        if(n_char == -1){
        write(1, "\n", 1);
        exit(1);
        }
        buffer[n_char - 1] ='\0';
	char **tokens = splitter(buffer);
	if (strcmp(tokens[0]
return(0);
}
