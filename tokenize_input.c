#include "shell.h"

/**
 * * my_tokenize - Tokenize a string into simple tokens using space as a delimiter.
 * *
 * * @input_str: Pointer to the string to be tokenized.
 * * Return: An array of pointers representing the command tokens.
 * */
char **tokenize_input(char **input_str)
{
	char *token_x;
	char *token_y;
	char *input_copy = strdup(*input_str);
	char **tokens = NULL;
	int token_count = 0;

	if (input_str == NULL)
		return NULL;

	token_x = strtok(*input_str, " ");
	for (; token_x != NULL; token_x = strtok(NULL, " "))
		token_count++;

	tokens = malloc((token_count + 1) * sizeof(char *));
	token_y = strtok(input_copy, " ");
	for (int i = 0; token_y != NULL; i++)
	{
		tokens[i] = strdup(token_y);
		token_y = strtok(NULL, " ");
	}

	tokens[token_count] = NULL;
	free(*input_str);
	free(input_copy);

	return tokens;
}

