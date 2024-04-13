#include "utils.h"

void cleanup(char* command)
{
    // Free the memory allocated for the command
    free(command);
}
