#include "shell.h"

/**
 * sig_handler - checks if Ctrl C is pressed
 * @signal: int
 */
void sig_handler(int signal)
{
if (signal == SIGINT)
{
write(1, "\n$ ", 4);
}
}
