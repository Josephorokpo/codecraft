C-Simple Shell
***ALX C-Simple Shell Team Project***
A simple UNIX command interpreter implemented in C. This shell provides basic functionalities for executing commands, handling built-in commands, logical operators, variable replacement, and more.

#Table of Contents
Introduction
Features
Usage
Built-in Commands
External Commands
Background Execution
Logical Operators
Variables
File as Input
Signal Handling
Error Handling
Memory Management
Testing
How to Run
Contributors
License
#Introduction
This simple shell is a basic implementation of a command-line interpreter. It allows users to enter commands and execute them, similar to a standard shell. The shell supports both built-in commands and external commands executed through the execve system call.

#Features
-Prompt display and waiting for user input
-Execution of basic commands using execve
-Handling of built-in commands, including exit, env, setenv, unsetenv, and cd
-Logical operators && and || for chaining commands
-Variable replacement for $? (exit status) and $$ (current process ID)
-Background execution of commands using the & symbol
-Reading commands from a file and executing them sequentially
#Usage
To use the shell, simply run the executable, and the shell prompt will be displayed. Enter your commands at the prompt and press Enter to execute them. To exit the shell, type exit and press Enter.

#Built-in Commands
The following built-in commands are supported:
-exit: Exit the shell.
-env: Display the current environment variables.
-setenv VARIABLE VALUE: Initialize a new environment variable or modify an existing one.
-unsetenv VARIABLE: Remove an environment variable.
-cd [DIRECTORY]: Change the current directory. If no argument is given, the shell will change to the home directory.
#External Commands
The shell can execute external commands by providing the command name. The shell will search for the command in the directories listed in the PATH environment variable.

#Background Execution
To execute a command in the background, use the & symbol at the end of the command.

#Logical Operators
The shell supports logical operators && and ||, which allow chaining of commands based on the success or failure of previous commands.

#Variables
The shell supports variable replacement for the following variables:

$?: Represents the exit status of the last executed command.
$$: Represents the current process ID.
#File as Input
The shell can take a file as a command-line argument, read commands from the file, and execute them sequentially. This mode does not display the shell prompt and does not read from stdin.

#Signal Handling
The shell handles the SIGINT signal (Ctrl+C) to prevent termination and take the program to the next line.

#Error Handling
The shell provides proper error messages for various scenarios, such as command not found, invalid syntax, etc.

#Memory Management
The shell ensures proper memory management and frees dynamically allocated memory to avoid memory leaks.

#Testing
The shell has been tested thoroughly with various scenarios and edge cases to ensure correct functionality.

#How to Run
Clone this repository to your local machine.
Compile the code using the provided compilation command:
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o simple_shell

Run the shell:
./simple_shell

Enter commands at the prompt and enjoy using the simple shell!
#Contributors
Joseph Orokpo
Burhanuddin Abdulahi
#License
Nil

