#include "shell.h"
#include <limits.h>

/**
 * cd_builtin - Change the current directory of the process.
 * @dir: The directory to change to. If NULL, change to the home directory.
 *
 * Return: 0 on success, -1 on failure.
 */
int cd_builtin(char *dir)
{
    char *new_dir = NULL;
    char current_dir[PATH_MAX];

    if (dir == NULL)
    {
        /* If no directory is specified, change to the home directory */
        new_dir = getenv("HOME");
        if (new_dir == NULL)
        {
            perror("cd_builtin");
            return (-1);
        }
    }
    else if (strcmp(dir, "-") == 0)
    {
        /* If "-" is specified, change to the previous directory */
        new_dir = getenv("OLDPWD");
        if (new_dir == NULL)
        {
            perror("cd_builtin");
            return (-1);
        }
    }
    else
    {
        new_dir = dir;
    }

    if (getcwd(current_dir, sizeof(current_dir)) == NULL)
    {
        perror("cd_builtin");
        return (-1);
    }

    if (chdir(new_dir) == -1)
    {
        perror("cd_builtin");
        return (-1);
    }

    /* Update the PWD environment variable */
    if (setenv("PWD", getcwd(current_dir, sizeof(current_dir)), 1) == -1)
    {
        perror("cd_builtin");
        return (-1);
    }

    return (0);
}
