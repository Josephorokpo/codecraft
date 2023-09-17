#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>
#include <errno.h>
#include <ctype.h>

/* Function prototypes */
extern char **environ;
char **fetch_command(int *main_loop);
void strip_input(char *line);
void free_command(char **cmd);
int is_executable(char **cmd);
void findExecutablePath(char **cmdname);
void print_environment(void);
void exec_command(char **cmd, int *errors, int *exit_status);
char **tokenize_input(char **input_str);

#endif
