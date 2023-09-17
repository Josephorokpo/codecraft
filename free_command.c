#include "shell.h"

/**
 * free_command - Free memory allocated for a command.
 * @cmd: An array of strings representing the command and its arguments.
 */
void free_command(char **cmd)
{
	int i = 0;

	if (cmd != NULL)
	{
		while (cmd[i] != NULL)
		{
			free(cmd[i]);
			i++;
		}
		free(cmd);
		cmd = NULL; /* Set the pointer to NULL after freeing */
	}
}
