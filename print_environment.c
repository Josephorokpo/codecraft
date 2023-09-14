#include "shell.h"
#include <unistd.h>
/**
 * print_environment - Print the environment variables
 */
void print_environment(void)
{
	extern char **environ;

	char **env = environ; /* Access the environment variable using the global variable environ */

	while (*env != NULL)
	{
		write(STDOUT_FILENO, *env, strlen(*env)); /* Print each environment variable using write */
		write(STDOUT_FILENO, "\n", 1); /* Add a newline character */
		env++;
	}
}
