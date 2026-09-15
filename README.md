\# Command Pipeline Visualizer

Command Pipeline Visualizer is an Operating Systems project designed
to help beginners understand how commands in a Unix pipeline interact.

## Project Objective

The project provides a visual approach to understanding command
pipelines, showing how the output of one command becomes the input
of the next command.

## Example Pipeline

cat file.txt | grep "pattern" | sort

## Week 1 Features

- Linux development environment
- C source code
- Interactive pipeline input
- REPL loop
- Makefile-based build
- Git repository setup
- GitHub repository setup

## Week 2 Features

- Dynamic command input handling
- Multiple command input
- `read_commands()` function for reading commands
- Dynamic memory allocation using `malloc()` and `realloc()`
- Command storage and command counting
- `free_commands()` for memory cleanup
- Updated Makefile to compile `src/input.c`
- Commands displayed in the order they were entered
- Improved handling of empty command input

## Project Structure

Project/
├── src/
├── include/
├── docs/
├── tests/
├── screenshots/
├── bin/
├── Makefile
├── README.md
└── .gitignore

## Build

make

## Run

make run

## Exit

Type:

exit

## Future Development

Future stages will parse pipeline commands, identify individual
commands, execute pipeline processes, and visualize the flow of
data between pipeline stages.
## Week 3 Features

- Command parsing using `strtok()`
- Dynamic `argv[]` construction
- Modular parser implementation
- Tokenized command arguments
- Memory cleanup using `free_tokens()`
