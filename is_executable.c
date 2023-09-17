#include "shell.h"

/**
 * is_executable - Check if a command is executable in the PATH
 * or has a full pathname.
 * @cmd: The command to check
 *
 * Return values:
 *   - NULL: Memory allocation failure.
 *   - 2: Full executable pathname.
 *   - 1: Executable in PATH.
 *   - 0: Not executable or not in PATH.
 */
int is_executable(char **cmd)
{
	char *path = getenv("PATH");
	char *path_copy = NULL;
	char *token = NULL;
	char *try_path = NULL;
	int result = 0; /* Default: Not executable or not in PATH */

	/* Check for full executable pathname */
	if (access(cmd[0], X_OK) == 0 && cmd[0][0] == '/')
	{
		return (2); /* Full executable pathname */
	}

	if (path == NULL)
	{
		return (0); /* Not in PATH */
	}

	path_copy = strdup(path);
	if (path_copy == NULL)
	{
		perror("strdup");
		return (-1); /* Memory allocation failure */
	}

	token = strtok(path_copy, ":");

	while (token != NULL)
	{
		try_path = malloc(strlen(token) + strlen(cmd[0]) + 2);
		if (try_path == NULL)
		{
			perror("malloc");
			free(path_copy);
			return (-1); /* Memory allocation failure */
		}

		sprintf(try_path, "%s/%s", token, cmd[0]);

		if (access(try_path, X_OK) == 0)
		{
			free(path_copy);
			free(try_path);
			return (1); /* Executable in PATH */
		}

		free(try_path);
		token = strtok(NULL, ":");
	}

	free(path_copy);
	return (result); /* Not executable or not in PATH */
}
