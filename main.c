#include "shell.h" 

/**
 * main - Entry point of the shell program
 * @ac: The number of arguments passed to the program
 * @av: An array of strings containing the arguments
 *
 * Return: The exit status of the shell program.
 */
int main(int ac, char **av)
{
	int main_loop = 1;
	int exit_status = 0;
	int errors = 0;
	int is_executable_flag;
	char **cmd = NULL;
	ac = ac;

	while (main_loop)
	{
		cmd = fetch_command(&main_loop);
		if (cmd != NULL)
		{
			if (strcmp(cmd[0], "exit") == 0)
			{
				free_command(cmd);
				break;
			}
			if (strcmp(cmd[0], "env") == 0)
			{
				print_environment();
				exit_status = 0;
				free_command(cmd);
				continue;
			}
			is_executable_flag = is_executable(&cmd[0]);
			if (is_executable_flag == 0)
			{
				(errors)++;
				fprintf(stderr, "%s: %d: %s: COMMAND NOT FOUND\n", av[0], errors, cmd[0]);
				exit_status = 127;
				free_command(cmd);
				continue;
			}
			else if (is_executable_flag == 1)
				findExecutablePath(&cmd[0]);

			exec_command(cmd, &errors, &exit_status);
			}
		}

	return (exit_status);
}
