#include <stdio.h>
#include "pipeline.h"
#include "input.h"
#include "parser.h"
#include "process.h"
#include "builtin.h"

int main()
{
    int count = 0;
    char **commands;

    printf("=====================================\n");
    printf("       COMMAND PIPELINE VISUALIZER\n");
    printf("=====================================\n");
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
