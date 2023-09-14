#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>

#define MAX_TOKENS 100 /* Maximum number of tokens */

/* Function prototypes */
char **fetch_command(int *main_loop);
void strip_input(char *input);
void free_command(char **cmd);
int is_executable(char **cmd);
void find_path(char **cmd);
void print_environment(void);
void exec_command(char **cmd, int *errors, int *exit_status);
char **tokenize_input(char *input);

#endif

