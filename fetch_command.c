#include "shell.h"

/**
 * * read_user_input - Reads and processes user input to obtain a command.
 * *
 * * @shell_control: Pointer to control the shell's operations (enable/disable)
 * *
 * * Return: An array of command tokens, or NULL if there's an issue.
 * */
char **fetch_command(int *shell_control)
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
		*shell_control = 0;
		return (NULL);
	}
	strip_input(line);
	if (strlen(line) == 0 || read == -1)
	{
		free(line);
		return (NULL);
	}
	command = tokenize_input(&line);
	return (command);
}
