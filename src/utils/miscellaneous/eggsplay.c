#include "utils.h"

void eggsplay(char* message)
{
    // Write the message to the STDOUT, a custom printf function
    write(STDOUT_FILENO, message, strlen(message));
}

