#include "shell.h"
int main(int ac, char **av)
{
    (void)ac;
    (void)av; 
    ssize_t len = 0;
        char *buffer = NULL;
        int token_size = 0;
	size_t size = 0;
        int n_char = 0;

        write(1,"$ ",2);
        n_char = getline(&buffer, &size, stdin);
        if(n_char == -1){
        perror("getline");
        exit(EXIT_FAILURE);
        }
        buffer[n_char - 1] ='\0';
	char **tokens = splitter(buffer);
return(0);
}
