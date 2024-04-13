#include "utils.h"

#define INITIAL_BUFFER_SIZE 2048

// Function to read a command from the user
char* readCommand()
{
    // Initialize buffer size and allocate memory for the command
    int bufferSize = INITIAL_BUFFER_SIZE;
    char* userCommand = (char*) malloc(bufferSize * sizeof(char));

    // If memory allocation fails, print an error message and exit
    if (userCommand == NULL)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    size_t charIndex = 0;
    int inputChar;

    // Read the first character
    inputChar = getchar();

    // If the first character is a newline, free the memory and return NULL
    if (inputChar == '\n')
    {
        free(userCommand);
        return NULL;
    }

    // Read characters until a newline or EOF is encountered
    while (inputChar != '\n' && inputChar != EOF)
    {
        // Add the character to the command
        userCommand[charIndex++] = (char) inputChar;

        // If the buffer is full, increase its size
        if (charIndex >= bufferSize)
        {
            bufferSize += INITIAL_BUFFER_SIZE;
            userCommand = realloc(userCommand, bufferSize);

            // If memory reallocation fails, print an error message and exit
            if (userCommand == NULL)
            {
                perror("Error:");
                exit(EXIT_FAILURE);
            }
        }

        // Read the next character
        inputChar = getchar();
    }

    // If EOF is encountered and no characters have been read, print a newline and exit
    if (inputChar == EOF && charIndex == 0)
    {
        printf("\n");
        exit(EXIT_SUCCESS);
    }

    // Null-terminate the command and return it
    userCommand[charIndex] = '\0';
    return userCommand;
}

/*
 * define INITIAL_SIZE 50
 *
 * currrentBuffer = INITIAL_SIZE
 * char *command = (char*) malloc(sizeof(char) * currentBuffer);
 *
 * char ch = getchar()
 *
 * while ((getchar()) != EOF)
 * {
 *      command[n] =
 * }
 *
 *
 *
 *
 */
