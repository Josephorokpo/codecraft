#include "shell.h"

/**
 * findExecutablePath - Search for the command in directories listed in the PATH variable
 * @cmdname: The command to find
 */
void findExecutablePath(char **cmdname)
{
	char *path_copy = NULL;
	char *token = NULL;
	char *trypath = NULL;

	char *path = getenv("PATH");
	if (path == NULL)
	{
		fprintf(stderr, "Error: PATH environment variable not found.\n");
		return;
	}

	path_copy = strdup(path);
	if (path_copy == NULL)
	{
		perror("Error: Memory allocation failed");
		return;
	}

	token = strtok(path_copy, ":");

	while (token != NULL)
	{
		trypath = malloc(strlen(*cmdname) + strlen(token) + 2);
		if (trypath == NULL)
		{
			perror("Error: Memory allocation failed");
			free(path_copy);
			return;
		}

		sprintf(trypath, "%s/%s", token, *cmdname);

		if (access(trypath, X_OK) == 0)
		{
			free(*cmdname);
			*cmdname = strdup(trypath);
			free(trypath);
			break;
		}

		free(trypath);
		token = strtok(NULL, ":");
	}

	free(path_copy);
}
