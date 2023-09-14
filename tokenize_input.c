#include "shell.h"

/**
 * tokenize_input - Tokenize a string into simple tokens using space as a delimiter.
 *
 * @input: Pointer to the string to be tokenized.
 * Return: An array of pointers representing the command tokens.
 */
char **tokenize_input(char *input)
{
	char *token;
	char *input_copy = strdup(input);
	char **command = NULL;
	int i;
	int token_count = 0;

	if (input == NULL)
		return (NULL);

	/* Allocate memory for tokens */
	command = malloc((MAX_TOKENS + 1) * sizeof(char *));
	if (command == NULL)
	{
		free(input_copy);
		return (NULL);
	}

	/* Tokenize input_copy */
	token = strtok(input_copy, " \t\n");
	while (token != NULL)
	{
		if (token_count >= MAX_TOKENS)
		{
			fprintf(stderr, "Exceeded maximum token count (%d)\n", MAX_TOKENS);
			free(command);
			free(input_copy);
			return (NULL);
		}

		/* Allocate memory for the token and copy it */
		command[token_count] = strdup(token);
		if (command[token_count] == NULL)
		{
			/* Clean up command and input_copy before exiting */
			for (i = 0; i < token_count; i++)
			{
				free(command[i]);
			}
			free(command);
			free(input_copy);
			return (NULL);
		}

		token_count++;
		token = strtok(NULL, " \t\n");
	}

	/* Set the last token as NULL */
	command[token_count] = NULL;

	/* Free input_copy */
	free(input_copy);

	return (command);
}
