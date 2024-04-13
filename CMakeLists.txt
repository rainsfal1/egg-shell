cmake_minimum_required(VERSION 3.27)

#project name
project(shellProject)

# C standard
set(CMAKE_C_STANDARD 23)

include_directories(include)

add_executable(shellProject
        src/main.c
        src/utils/miscellaneous/eggsplay.c
        src/utils/mainloop/displayPrompt.c
        src/utils/mainloop/executeCommand.c
        src/utils/miscellaneous/initialize.c
        src/utils/mainloop/readCommand.c
        src/utils/miscellaneous/shutdown.c
        src/utils/miscellaneous/eggsplay.c
        src/utils/miscellaneous/eggsplay.c
        src/utils/mainloop/readCommand.c
        src/utils/mainloop/cleanup.c
        src/utils/mainloop/parseCommand.c
        src/commands/commands.c
        include/tictactoe.h
)


