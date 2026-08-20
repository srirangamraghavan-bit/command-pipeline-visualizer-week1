#include <stdio.h>
#include <string.h>
#include "pipeline.h"
#include "input.h"

int main()
{
    int count = 0;
    char **commands;

    printf("========================================\n");
    printf("       COMMAND PIPELINE VISUALIZER\n");
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
        printf("%d. %s\n", i + 1, commands[i]);
    }

    printf("\nTotal commands: %d\n", count);

    free_commands(commands, count);

    return 0;
}
