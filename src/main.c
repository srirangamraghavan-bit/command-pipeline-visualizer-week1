
#include <stdio.h>
#include <string.h>
#include "pipeline.h"
#include "input.h"
#include "parser.h"
#include "process.h"
#include "builtin.h"
#include "signals.h"
#include "pipes.h"
int main()
{
    initialize_signals();

    int count = 0;
    char **commands;

    printf("=================================\n");
    printf("       COMMAND PIPELINE VISUALIZER\n");
    printf("=================================\n");
    printf("Enter command pipelines.\n");
    printf("Type 'exit' when finished.\n");

    commands = read_commands(&count);

    if (commands == NULL)
    {
        printf("No commands were entered.\n");
        return 1;
    }

    printf("\nCommands received:\n");

    for (int i = 0; i < count; i++)
    {
        printf("\n%d. %s\n", i + 1, commands[i]);

        char *pipe_pos = strchr(commands[i], '|');

        if (pipe_pos != NULL)
        {
            *pipe_pos = '\0';

            char *cmd1_line = commands[i];
            char *cmd2_line = pipe_pos + 1;

            char **cmd1 = parse_line(cmd1_line);
            char **cmd2 = parse_line(cmd2_line);

            if (cmd1 != NULL && cmd2 != NULL)
            {
                execute_pipe(cmd1, cmd2);
            }

            free_tokens(cmd1);
            free_tokens(cmd2);

            continue;
        }        


char **tokens = parse_line(commands[i]);

        if (tokens == NULL)
        {
            printf("Parsing failed.\n");
            continue;
        }

        printf("Tokens:\n");

        for (int j = 0; tokens[j] != NULL; j++)
        {
            printf("argv[%d] = %s\n", j, tokens[j]);
        }

        int builtin_status = execute_builtin(tokens);

        if (builtin_status == 2)
        {
            free_tokens(tokens);
            free_commands(commands, count);
            return 0;
        }

        if (builtin_status == 0)
        {
            execute(tokens);
        }

        free_tokens(tokens);
    }

    printf("\nTotal commands: %d\n", count);

    free_commands(commands, count);

    return 0;
}
