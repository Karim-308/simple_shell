<h1 align="center">
  Basic Shell Project
</h1>

<p align="center">
   📝 🚀
</p>

<p align="center">
  <strong>
   Project Overview
  </strong>
</p>

<p align="center">
This project is a custom implementation of a Unix-like shell, developed as a key project in the C programming curriculum at ALX Africa Software Engineering. </br>
It serves as an introductory exploration of advanced concepts such as process management, system calls, bit-level operations, file handling, and error management. </br>
The shell is a simple command interpreter that emulates the basic functionalities of the original Unix shell (sh). </br>
This program is fully developed in the C programming language.
</p>

## COPYRIGHT
Copyright (C) 2024 by [**Karim Ibrahim**](https://github.com/Karim-308) and [**Hatem Ashraf**](https://github.com/Hatem-Ashraf)</br>
All rights reserved 


## Project Description:
This shell is developed in [C](https://en.wikipedia.org/wiki/C_(programming_language)) and is inspired by the [Thompson Shell](https://en.wikipedia.org/wiki/Thompson_shell).

## Development Environment:

The shell was developed and tested on Ubuntu 14.04 LTS.

## Core Features:
* Displays a command prompt and waits for user input. Each command line input ends with a newline.
* If the specified executable is not found, an error message is displayed, and the prompt is shown again.
* Handles errors efficiently.
* Manages the "end of file" condition (Ctrl+D).
* Processes command line arguments.
* Manages the PATH environment variable.
* Supports shell exit commands and exit statuses.
* Ensures the shell does not terminate when Ctrl-C is pressed.
* Supports command separators `;`.
* Handles logical operators `&&` and `||`.
* Manages variable replacements like `$?` and `$$`.
* Recognizes and processes comments with `#`.
* Supports command history.
* Allows input from files.

## Built-in Commands:
Our shell supports the following built-in commands:

| Command             | Functionality                                                                            |
| ------------------- | ----------------------------------------------------------------------------------------- |
| exit [n]            | Exit the shell, with an optional exit status, n.                                          |
| env                 | Display the environment variables.                                                        |
| setenv [var][value] | Set or update an environment variable.                                                    |
| alias[name[='value]]| Display or define aliases.                                                                |
| unsetenv [var]      | Remove an environment variable.                                                           |
| cd [dir]            | Change the current directory.                                                             |
| help [built-in]     | Display help information for a built-in command.                                          |

## Installation Guide: Setting Up the Shell

To get started, clone the repository and compile the source files using GCC.

```bash
git clone https://github.com/Karim-308/simple_shell.git
```


### Basic Usage 💡:
- First, fork the repository [Learn how to fork a repo](https://docs.github.com/en/github/getting-started-with-github/fork-a-repo).
- Then, clone your fork [Learn how to clone](https://docs.github.com/en/github/creating-cloning-and-archiving-repositories/cloning-a-repository).
- Compile the source files into an executable with the following command:
  ```bash
  gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
  ```

### To run :
  ```bash
./hsh
  ```

### Now enjoy 

### Contributors:
- [**Karim Ibrahim**](https://github.com/Karim-308)
- [**Hatem Ashraf**](https://github.com/Hatem-Ashraf)




