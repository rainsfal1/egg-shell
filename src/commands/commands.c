#include "../include/utils.h"
#include "../include/commands.h"
#include "../include/tictactoe.h"

// Function to display help information for built-in commands
void handle_help(void)
{
    eggsplay("\n------------------ SHELL HELP ------------------\n");
    eggsplay("cd: Changes the current working directory.\n");
    eggsplay("ls: Lists directory contents.\n");
    eggsplay("pwd: Prints the path of the working directory.\n");
    eggsplay("exit: Exits the shell.\n");
    eggsplay("echo: Outputs specified arguments.\n");
    eggsplay("clear: Clears the terminal display.\n");
    eggsplay("help: Provides help information for built-in commands.\n");
    eggsplay("date: Shows the current system date and time.\n");
    eggsplay("tictactoe: Starts the game \"tictactoe\".\n");
    eggsplay("------------------------------------------------\n");
}

// Function to handle 'ls' command
void handle_ls() {
    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    if (d) {
        printf("--------------------\n");
        while ((dir = readdir(d)) != NULL) {
            if (strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0) {
                printf("| %s\n", dir->d_name);
            }
        }
        printf("--------------------\n");
        closedir(d);
    }
}

// Function to handle 'echo' command
void handle_echo(char **commandArguments)
{
    int i = 1;
    // Print each argument followed by a space
    while(commandArguments[i] != NULL)
    {
        printf("%s ", commandArguments[i]);
        i++;
    }
    printf("\n");
}

// Function to handle 'clear' command
void handle_clear()
{
    // Write the ANSI escape code to the standard output
    eggsplay("\033[H\033[J");
}

// Function to handle 'pwd' command
void handle_pwd(void) {
    char cwd[1024];
    // Get the current working directory
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        eggsplay(cwd);
        eggsplay("\n");
    } else {
        // Print error message if getcwd fails
        perror("Error");
    }
}

// Function to handle 'date' command
void handle_date() {
    // Execute 'date' command in the system shell
    system("date");
}

// Function to handle 'cd' command
void handle_cd(char **commandArguments) {
    // Check if directory is specified
    if (commandArguments[1] == NULL) {
        fprintf(stderr, "Expected argument to \"cd\"\n");
    } else {
        // Change the current directory
        if (chdir(commandArguments[1]) != 0) {
            // Print error message if chdir fails
            perror("Error");
        }
    }
}

// Function to handle 'tictactoe' command
void handle_tictactoe(void) {
    // Start the Tic-Tac-Toe game with the human player's turn
    playTicTacToe(PLAYER);
}

