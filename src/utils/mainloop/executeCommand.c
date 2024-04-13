#include "utils.h"
#include "commands.h"

#define SHELL_DELIMITERS " \r\t;&|\a\n"

int executeCommand(const char *inputCommand)
{

    // Parse the input command into arguments
    char **commandArguments = parseCommand(inputCommand);

    // If the command is 'exit', shutdown the shell and exit
    if (commandArguments[0] != NULL && strcmp(commandArguments[0], "exit") == 0)
    {
        shutdown();
        exit(EXIT_SUCCESS);
    }

    // If fork failed, print an error message and exit
    pid_t processID = fork();

    if (processID == -1)
    {
        perror("Error:");
        exit(EXIT_FAILURE);
    }

        // In the child process
    else if (processID == 0)
    {
        // Handle various commands
        // Check if the command is 'ls'
        if (strcmp(commandArguments[0], "ls") == 0)
        {
            handle_ls();
        }
            // Check if the command is 'echo'
        else if (strcmp(commandArguments[0], "echo") == 0)
        {
            handle_echo(commandArguments);
        }
            // Check if the command is 'help'
        else if (strcmp(commandArguments[0], "help") == 0)
        {
            handle_help();
        }
            // Check if the command is 'clear'
        else if (strcmp(commandArguments[0], "clear") == 0)
        {
            handle_clear();
        }
            // Check if the command is 'pwd'
        else if (strcmp(commandArguments[0], "pwd") == 0)
        {
            handle_pwd();
        }
            // Check if the command is 'date'
        else if (strcmp(commandArguments[0], "date") == 0)
        {
            handle_date();
        }
            // Check if the command is 'cd'
        else if (strcmp(commandArguments[0], "cd") == 0)
        {
            handle_cd(commandArguments);
        }

            // Check if the command is 'tictactoe'
        else if (commandArguments[0] != NULL && strcmp(commandArguments[0], "tictactoe") == 0)
        {
            handle_tictactoe();
            printf("\n");
        }
        else {
            if (execvp(commandArguments[0], commandArguments) == -1) {
                perror("Error");
                exit(EXIT_FAILURE);
            }
        }
    }
        // In the parent process
    else
    {
        // Wait for the child process to finish
        waitpid(processID, &status, 0);
    }

    return 1;
}
