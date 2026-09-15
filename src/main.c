#include <stdio.h>
#include "pipeline.h"
#include "input.h"
#include "parser.h"
#include "process.h"
int main()
{
    int count = 0;
    char **commands;

    printf("========================================\n");
    printf("        COMMAND PIPELINE VISUALIZER\n");
    printf("========================================\n");
    printf("Enter command pipelines.\n");
    printf("Type 'exit' when finished.\n\n");

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

        printf("Tokens:\n");

        for (int j = 0; tokens[j] != NULL; j++)
        {
            printf("argv[%d] = %s\n", j, tokens[j]);
        }
        execute(tokens);
        free_tokens(tokens);
    }

    printf("\nTotal commands: %d\n", count);

    free_commands(commands, count);

    return 0;
}
