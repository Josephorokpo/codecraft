#include "shell.h"
#include <stdbool.h>

/**
 * strip_input - Removes leading and trailing whitespaces,
 *               and reduces multiple spaces between tokens
 *               to a single space.
 *
 * @input: Pointer to the string to be stripped
 */
void strip_input(char *input)
{
	size_t length = strlen(input);
	size_t start = 0;
	size_t end = length - 1;
	size_t i, j;
	bool insideToken = false;

	if (input == NULL)
		return;

	while (start < length && isspace(input[start]))
		start++;

	while (end > start && isspace(input[end]))
		end--;

	for (i = start, j = 0; i <= end; i++)
	{
		if (isspace(input[i]))
		{
			if (!insideToken)
			{
				input[j++] = ' ';
				insideToken = true;
			}
		}
		else
		{
			input[j++] = input[i];
			insideToken = false;
		}
	}

	input[j] = '\0';
}
