#include "shell.h"

/**
 * print_environment - Print the environment variables
 */
void print_environment(void)
{
	char **envp = environ;

	for (; envp != NULL && *envp != NULL; envp++)
		printf("%s\n", *envp);
}
