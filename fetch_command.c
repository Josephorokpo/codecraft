#include "shell.h"

/**
 * fetch_command - Read and tokenize a user command from standard input.
 *
 * @main_loop: A pointer to an integer controlling the main loop.
 *
 * Return:
 *   A dynamically allocated array of strings representing the tokens
 *   of the user command, or NULL on end-of-file or error conditions.
 */
char **fetch_command(int *main_loop)
{
	char **command = NULL;
	char *line = NULL;
	size_t size = 0;
	ssize_t read;

	if (isatty(STDIN_FILENO))
	{
		printf("$ ");
		fflush(stdout);
	}
	read = getline(&line, &size, stdin);

	if (feof(stdin))
	{
		if (isatty(STDIN_FILENO))
			printf("\n");
		free(line);
		*main_loop = 0;
		return (NULL);
	}
	else if (strlen(line) == 1 && line[0] == '\n')
	{
		free(line);
		return (NULL);
	}
	strip_input(line);

	if (strlen(line) == 0 || read == -1)
	{
		free(line);
		return (NULL);
	}

	command = tokenize_input(line);

	/* Free the line since it's no longer needed */
	free(line);

	/* Handle potential memory allocation failure */
	if (command == NULL)
	{
		fprintf(stderr, "Failed to tokenize input\n");
		return (NULL);
	}

	return (command);
}
