#include "shell.h"

/**
 * exec_command - Execute a command with enhanced error handling
 * @cmd: An array of strings representing the command and its arguments
 * @errors: A pointer to an integer to track the number of errors
 * @exit_status: A pointer to an integer to store the exit status of the command
 */

void exec_command(char **cmd, int *errors, int *exit_status)
{
	pid_t child_pid = 0;
	int child_status = 0;

	child_pid = fork(); /* Create a child process */

	if (child_pid == -1)
	{
		perror("fork");
		(*errors)++;
		*exit_status = 1; /* Set an appropriate exit status for fork error */
		return; /* Return to avoid executing the rest of the function */
	}

	if (child_pid == 0)
	{
		/* This code runs in the child process */

		/* Execute the command using execve */
		if (execve(cmd[0], cmd, NULL) == -1)
		{
			perror("execve");
			(*errors)++;
			*exit_status = 1; /* Set an appropriate exit status for execve failure */
			exit(1); /* Exit the child process on execve failure */
		}
	}
	else
	{
		/* This code runs in the parent process */

		/* Wait for the child process to complete */
		if (waitpid(child_pid, &child_status, 0) == -1)
		{
			perror("waitpid");
			(*errors)++;
			*exit_status = 1; /* Set an appropriate exit status for waitpid error */
		}
		else
		{
			/* Check if the child process exited normally */
			if (WIFEXITED(child_status))
			{
				*exit_status = WEXITSTATUS(child_status);
			}
			else if (WIFSIGNALED(child_status))
			{
				perror("Child process terminated by signal");
				(*errors)++;
				*exit_status = 1; /* Set an appropriate exit status for signal termination */
			}
		}
	}
}
