#include "shell.h"

/**
 * find_path - Search for the command in directories listed in the PATH variable
 * @cmd: The command to find
 */
void find_path(char **cmd)
{
	char *path = getenv("PATH");
	char *full_path = NULL;
	char *command = cmd[0];
	char *token = NULL;

	if (path == NULL)
	{
		/* PATH variable is not set, or an error occurred while accessing it */
		return;
	}

	token = strtok(path, ":");
	while (token != NULL)
	{
		/* +2 for '/' and null terminator */
		full_path = malloc(strlen(token) + strlen(command) + 2); 
		if (full_path == NULL)
		{
			perror("malloc");
			return;
		}

		sprintf(full_path, "%s/%s", token, command);

		/* Check if the constructed path is executable */
		if (access(full_path, X_OK) == 0)
		{
			/* Update the command with the full path */
			free(cmd[0]);
			cmd[0] = strdup(full_path);
			free(full_path);
			return;
		}

		free(full_path);

		token = strtok(NULL, ":");
	}
}
