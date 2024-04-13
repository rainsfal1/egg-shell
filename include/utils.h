#ifndef UTILS_H  // Prevents the header file from being included more than once
#define UTILS_H

// Standard library headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>
#include <stdbool.h>
#include <dirent.h>
#include <sys/wait.h>

// Global variable to hold the status of the shell
int status;

// Function to display a message to the console
void eggsplay(char* message);

// Function to parse the input command into a format that can be executed
char** parseCommand(const char* inputCommand);

// Function to perform initial setup for the shell
void initialize(void);

// Function to display the shell prompt to the user
void displayPrompt(void);

// Function to read the command input by the user
char* readCommand(void);

// Function to execute the input command
int executeCommand(const char* command);

// Function to clean up resources after command execution
void cleanup(char* command);

// Function to perform cleanup and exit the shell
void shutdown(void);

// End of header guard
#endif