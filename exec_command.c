#include "shell.h"

/**
 * exec_command - Execute a command with enhanced error handling
 * @cmd: An array of strings representing the command and its arguments
 * @errors: A pointer to an integer to track the number of errors
 * @exit_status: Pointer to an integer to store the exit status of the command
 */

void exec_command(char **cmd, int *errors, int *exit_status)
{
	pid_t child_pid;
	int child_status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		return;
	}

	if (child_pid == 0)
	{
		if (execve(cmd[0], cmd, environ) == -1)
		{
			(*errors)++;
			perror("Failed Execve");
		}
		free_command(cmd);
	}
	else
	{
		wait(&child_status);
		if (WIFEXITED(child_pid))
		{
			*exit_status = WEXITSTATUS(child_status);
		}
		else if (WIFSIGNALED(child_status))
		{
			fprintf(stderr, "signal terminated child process: %d\n", WTERMSIG(child_status));
			*exit_status = WTERMSIG(child_status);
			(*errors)++;
		}

		free_command(cmd);
	}
}
