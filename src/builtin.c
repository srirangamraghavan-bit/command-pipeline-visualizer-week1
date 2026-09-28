#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "builtin.h"

int execute_builtin(char **args)
{
    if (args == NULL || args[0] == NULL)
        return 0;

    if (strcmp(args[0], "cd") == 0)
    {
        if (args[1] == NULL)
        {
            fprintf(stderr, "cd: missing argument\n");
        }
        else if (chdir(args[1]) != 0)
        {
            perror("cd");
        }

        return 1;
    }

    if (strcmp(args[0], "pwd") == 0)
    {
        char cwd[1024];

        if (getcwd(cwd, sizeof(cwd)) != NULL)
            printf("%s\n", cwd);
        else
            perror("pwd");

        return 1;
    }

    if (strcmp(args[0], "clear") == 0)
    {
        printf("\033[2J\033[H");
        return 1;
    }

    if (strcmp(args[0], "exit") == 0)
    {
        return 2;
    }

    return 0;
}
