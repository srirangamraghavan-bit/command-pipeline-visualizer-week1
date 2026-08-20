#include <stdio.h>
#include <string.h>
#include "pipeline.h"

int main()
{
    char input[MAX_INPUT];

    printf("========================================\n");
    printf("     COMMAND PIPELINE VISUALIZER\n");
    printf("========================================\n");
    printf("Enter a command pipeline or type 'exit'.\n\n");

    while (1)
    {
        printf("pipeline> ");

        if (fgets(input, sizeof(input), stdin) == NULL)
            break;

        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") == 0)
        {
            printf("Exiting Command Pipeline Visualizer...\n");
            break;
        }

        if (strlen(input) == 0)
        {
            continue;
        }

        printf("\nPipeline received: %s\n", input);
        printf("Pipeline analysis will be implemented in the next stage.\n\n");
    }

    return 0;
}
