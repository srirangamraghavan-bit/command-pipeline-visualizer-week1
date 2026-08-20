#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"

#define INITIAL_CAPACITY 4
#define MAX_COMMAND_LENGTH 256

char **read_commands(int *count)
{
    int capacity = INITIAL_CAPACITY;
    char **commands = malloc(capacity * sizeof(char *));

    if (commands == NULL)
    {
        perror("malloc");
        return NULL;
    }

    *count = 0;

    char buffer[MAX_COMMAND_LENGTH];

    while (1)
    {
        printf("Enter command (or 'done' to finish): ");

        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
            break;

        buffer[strcspn(buffer, "\n")] = '\0';

        if (strcmp(buffer, "done") == 0)
            break;

        if (strlen(buffer) == 0)
            continue;

        if (*count >= capacity)
        {
            capacity *= 2;

            char **temp = realloc(commands,
                                  capacity * sizeof(char *));

            if (temp == NULL)
            {
                perror("realloc");
                free_commands(commands, *count);
                return NULL;
            }

            commands = temp;
        }

        commands[*count] = malloc(strlen(buffer) + 1);

        if (commands[*count] == NULL)
        {
            perror("malloc");
            free_commands(commands, *count);
            return NULL;
        }

        strcpy(commands[*count], buffer);
        (*count)++;
    }

    return commands;
}

void free_commands(char **commands, int count)
{
    if (commands == NULL)
        return;

    for (int i = 0; i < count; i++)
    {
        free(commands[i]);
    }

    free(commands);
}

