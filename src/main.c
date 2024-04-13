#include "../include/utils.h"

int main(int argc, char **argv) {

    // Initialization State
    initialize();

    // Main loop
    do {
        // Display Prompt State
        displayPrompt();

        // Read Command State
        char *inputCommand = readCommand();

        // Command Execution State
        status = executeCommand(inputCommand);

        // Cleanup State
        cleanup(inputCommand);

    } while (status);

    // Shutdown State
    shutdown();

    return EXIT_SUCCESS;
}
