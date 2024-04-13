# EggShell - A Command Line Interface Project

Welcome to "EggShell", a command line interface (CLI) project developed as part of my semester project. The project
is implemented in C and provides a simple yet interactive shell environment for users to execute commands. Moreover, it
also includes a tictactoe game, as per my professor's wishes.
## Project Structure

The project is organized as follows:

```
EggShell/
├── src/
│   ├── commands/commands.c (Command implementations)
│   ├── utils/ (Utility functions)
│   │   ├── eggsplay.c
│   │   └── ... 
│   └── main.c (Main entry point)
├── include/
│   ├── commands.h (Header for command implementations)
│   ├── utils.h (Header for utility functions)
│   └── tictactoe.h (Header for Tic-Tac-Toe game)
├── docs/
│   └── README.md 
└── Makefile (Build script)
```

## Building the Project

To compile the project, navigate to the build directory and execute the `make` command:

```bash
$ make
```

## Running the Project

After successful compilation, you can start the shell by running the generated executable:

```bash
$ ./shellProject
```

## Example Commands

Here are a few commands you can try in the EggShell:

**1. List files in the current directory:**
```bash
egg ~> ls
```

**2. Play a game of Tic-Tac-Toe:**
```bash
egg ~> tictactoe
```
## Acknowledgments

This project was developed with reference to the following resources:

1. `The Linux Command Line by William Shotts` : Provided comprehensive guide on getting familiar with the unix shell.
2. `C Programming: A Modern Approach by K. N King` : Best book for learning C programming, in depth.
3. `Operating System Concepts by Abraham and other authors` : Gave me a good understanding on how the OS really works.

## Closing Note

Thank you for exploring EggShell. Enjoy using this CLI interface and happy coding!
