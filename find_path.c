#include "shell.h"

/**
 * find_path - Search for the command in directories listed in the PATH variable
 * @cmd: The command to find
 */
void findExecutablePath(char **cmdname)
{
	char *path = getenv("PATH");
	if (path == NULL) {
		fprintf(stderr, "Error: PATH environment variable not found.\n");
		return;
	}

	char *path_copy = strdup(path);
	if (path_copy == NULL) {
		perror("Error: Memory allocation failed");
		return;
	}

	char *token = strtok(path_copy, ":");
	char *trypath = NULL;

	while (token != NULL)
	{
		trypath = malloc(strlen(*cmdname) + strlen(token) + 2);
		if (trypath == NULL) {
			perror("Error: Memory allocation failed");
			free(path_copy);
			return;
		}

		sprintf(trypath, "%s/%s", token, *cmdname);

		if (access(trypath, X_OK) == 0) {
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
