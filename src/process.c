#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "process.h"

int execute(char **tokens)
{
    pid_t pid;
    int status;

    if (tokens == NULL || tokens[0] == NULL)
    {
        return 1;
    }

    pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return 1;
    }

    if (pid == 0)
    {
        execvp(tokens[0], tokens);

        perror("execvp");
        exit(EXIT_FAILURE);
    }

    waitpid(pid, &status, 0);

    return 1;
}
