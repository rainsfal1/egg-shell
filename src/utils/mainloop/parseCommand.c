#include "utils.h"

#define SHELL_DELIMITERS " \r\t;&|\a\n"
#define TOKEN_BUFFER_SIZE 32

char** parseCommand(const char* inputCommand)
{
    int tokenBufferSize = TOKEN_BUFFER_SIZE;
    int tokenIndex = 0;
    char **commandTokens = malloc(tokenBufferSize * sizeof(char*));
    char *singleToken;

    if (!commandTokens) {
        fprintf(stderr, "Allocation error\n");
        exit(EXIT_FAILURE);
    }

    singleToken = strtok(inputCommand, SHELL_DELIMITERS);
    while (singleToken != NULL) {
        commandTokens[tokenIndex] = singleToken;
        tokenIndex++;

        if (tokenIndex >= tokenBufferSize) {
            tokenBufferSize += TOKEN_BUFFER_SIZE;
            commandTokens = realloc(commandTokens, tokenBufferSize * sizeof(char*));
            if (!commandTokens) {
                fprintf(stderr, "Allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        singleToken = strtok(NULL, SHELL_DELIMITERS);
    }
    commandTokens[tokenIndex] = NULL; // Ensure the array is NULL-terminated
    return commandTokens;
}
