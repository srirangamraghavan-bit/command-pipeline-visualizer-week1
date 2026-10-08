
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pipeline.h"
#include "input.h"
#include "parser.h"
#include "process.h"
#include "builtin.h"
#include "signals.h"
#include "pipes.h"
#include "redirect.h"

int main()
{
    initialize_signals();

    int count = 0;
    char **commands;

    printf("====================================");
    printf("\n      COMMAND PIPELINE VISUALIZER   \n");
    printf("====================================\n");
    printf("Enter command pipelines.\n");
    printf("Type 'exit' when finished.\n");

    commands = read_commands(&count);

    if (commands == NULL)
    {
        printf("No commands were entered.\n");
        return 1;
    }

    for (int i = 0; i < count; i++)
    {
        char *line = commands[i];

        if (strcmp(line, "exit") == 0)
        {
            break;
        }

        char **tokens = parse_line(line);

        if (tokens != NULL && tokens[0] != NULL)
        {
            if (execute_builtin(tokens) == 0)
            {
                if (execute_redirection(tokens) == 0)
                {
                    execute(tokens);
                }
            }
            free_tokens(tokens);
        }
    }

    return 0;
}
