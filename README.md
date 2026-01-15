# Minishell

A simple Unix shell implementation written in C that mimics the behavior of bash. This project is part of the 42 School curriculum and demonstrates low-level system programming concepts including process management, file descriptors, signal handling, and command parsing.

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Built-in Commands](#built-in-commands)
- [Shell Features](#shell-features)
- [Architecture](#architecture)
- [Project Structure](#project-structure)
- [Authors](#authors)

## Overview

Minishell is a minimal shell implementation that provides an interactive command-line interface for executing commands, managing processes, and handling I/O redirections. It includes support for pipelines, environment variables, signal handling, and several built-in commands.

## Features

### Core Functionality
- **Interactive Command Prompt**: Displays a customizable prompt and accepts user input
- **Command Execution**: Executes binaries from PATH or specified paths
- **Command History**: Navigate through previous commands using readline library
- **Exit Status Tracking**: Maintains the exit status of the last executed command (`$?`)

### Advanced Shell Features
- **Pipelines**: Chain multiple commands with `|` operator
- **Redirections**:
  - Input redirection (`<`)
  - Output redirection (`>`)
  - Append mode (`>>`)
  - Here-documents (`<<`)
- **Environment Variables**: Access and modify shell environment
- **Variable Expansion**: 
  - Parameter expansion (`$VAR`)
  - Exit status expansion (`$?`)
  - Process ID expansion (`$$`)
- **Quote Handling**: 
  - Single quotes (`'`) - prevent all expansions
  - Double quotes (`"`) - allow variable expansion
- **Tilde Expansion**: Expand `~` to HOME directory
- **Filename Expansion**: Wildcard pattern matching (globbing)
- **Subshells**: Execute commands in subshell context with `()`

### Signal Handling
- **SIGINT (Ctrl+C)**: Interrupts current command and displays new prompt
- **SIGQUIT (Ctrl+\\)**: Ignored in interactive mode
- **SIGTSTP (Ctrl+Z)**: Ignored (no job control)
- Proper signal handling in child processes

## Requirements

- **OS**: Linux or macOS
- **Compiler**: GCC or Clang with C99 standard support
- **Libraries**:
  - readline (libreadline-dev on Debian/Ubuntu)
  - ncurses (libncurses-dev on Debian/Ubuntu)
- **Make**: GNU Make

## Installation

### 1. Clone the repository
```bash
git clone <repository-url> minishell
cd minishell
```

### 2. Install dependencies

**On Debian/Ubuntu:**
```bash
sudo apt-get install libreadline-dev libncurses-dev
```

**On macOS:**
```bash
brew install readline
```

### 3. Compile the project
```bash
make
```

This will compile the project and create the `minishell` executable in the current directory.

### 4. Clean build files (optional)
```bash
make clean    # Remove object files
make fclean   # Remove object files and binary
make re       # Clean and recompile
```

## Usage

### Starting Minishell
```bash
./minishell
```

### Basic Commands
```bash
# Execute a command
minishell$ ls -la

# Use pipes
minishell$ cat file.txt | grep "pattern" | wc -l

# Input/Output redirection
minishell$ cat < input.txt > output.txt

# Append to file
minishell$ echo "new line" >> output.txt

# Here-document
minishell$ cat << EOF
> Line 1
> Line 2
> EOF

# Environment variables
minishell$ echo $PATH
minishell$ export MY_VAR="value"
minishell$ echo $MY_VAR

# Exit status
minishell$ ls non_existent_file
minishell$ echo $?

# Exit the shell
minishell$ exit
```

## Built-in Commands

Minishell implements the following built-in commands:

| Command | Description | Usage |
|---------|-------------|-------|
| `echo` | Display text with optional newline control | `echo [-n] [string ...]` |
| `cd` | Change the current directory | `cd [directory]` |
| `pwd` | Print working directory | `pwd` |
| `export` | Set environment variables | `export [VAR=value ...]` |
| `unset` | Remove environment variables | `unset [VAR ...]` |
| `env` | Display environment variables | `env` |
| `exit` | Exit the shell | `exit [status]` |

### Built-in Command Details

- **echo**: Prints arguments to stdout. Use `-n` flag to suppress trailing newline.
- **cd**: Changes current directory. Without arguments, changes to HOME directory. Supports `~` expansion.
- **pwd**: Displays the current working directory's absolute path.
- **export**: Creates or updates environment variables. Without arguments, displays all exported variables.
- **unset**: Removes environment variables from the shell environment.
- **env**: Displays all environment variables in `KEY=VALUE` format.
- **exit**: Exits the shell with an optional exit status code.

## Shell Features

### Pipeline Execution
Commands can be chained together using pipes (`|`), where the output of one command becomes the input of the next:
```bash
minishell$ ls | grep .c | wc -l
```

### Redirections
- **Input redirection (`<`)**: Read from a file instead of stdin
- **Output redirection (`>`)**: Write to a file, overwriting existing content
- **Append redirection (`>>`)**: Append to a file
- **Here-document (`<<`)**: Read input until a delimiter is encountered

```bash
minishell$ cat < input.txt > output.txt
minishell$ echo "log entry" >> logfile.txt
minishell$ cat << END > file.txt
```

### Variable Expansion
The shell expands variables prefixed with `$`:
```bash
minishell$ echo $USER
minishell$ echo "Exit status: $?"
minishell$ echo "Process ID: $$"
```

### Quote Processing
- **Single quotes (`'`)**: Preserve literal value of all characters
- **Double quotes (`"`)**: Allow variable expansion but prevent word splitting

```bash
minishell$ echo 'Value: $HOME'    # Output: Value: $HOME
minishell$ echo "Value: $HOME"    # Output: Value: /home/user
```

### Subshells
Execute commands in a subshell environment:
```bash
minishell$ (cd /tmp && pwd)
minishell$ pwd  # Still in original directory
```

## Architecture

The minishell project follows a modular architecture with clear separation of concerns:

### 1. **Lexer (Tokenization)**
- Reads input string and breaks it into tokens
- Identifies operators, words, quotes, and special characters
- Handles quote parsing and initial syntax validation

### 2. **Parser (Syntax Analysis)**
- Constructs an Abstract Syntax Tree (AST) from tokens
- Validates command syntax
- Identifies command types (simple, pipeline, subshell)
- Processes redirections and builds command structures

### 3. **Expander**
- Performs variable expansion (`$VAR`, `$?`, `$$`)
- Handles tilde expansion (`~`)
- Processes filename expansion (wildcards)
- Removes quotes after expansion

### 4. **Executor**
- Executes commands based on the AST
- Manages process creation (fork/exec)
- Handles built-in commands
- Sets up pipelines and redirections
- Manages file descriptors

### 5. **Subsystems**
- **Environment Management**: Handles environment variables (getenv, setenv, unsetenv)
- **Signal Handling**: Manages SIGINT, SIGQUIT, and other signals
- **Prompt System**: Generates and displays the command prompt
- **Path Resolution**: Resolves command paths from PATH variable

## Project Structure

```
minishell/
├── Makefile                    # Build configuration
├── README.md                   # Project documentation
├── include/                    # Header files
│   ├── minishell.h            # Main header
│   ├── lexer.h                # Lexer definitions
│   ├── syntax.h               # Parser/AST structures
│   ├── executer.h             # Execution structures
│   ├── expansion.h            # Expansion functions
│   ├── builtins.h             # Built-in commands
│   ├── subsystem.h            # Subsystem functions
│   └── wrappers.h             # System call wrappers
├── src/                       # Source code
│   ├── main.c                 # Entry point
│   ├── lexer/                 # Tokenization
│   ├── grammar/               # Parsing and syntax
│   ├── expansion/             # Variable/filename expansion
│   ├── executer/              # Command execution
│   ├── builtins/              # Built-in commands
│   ├── subsystem/             # Environment, signals, etc.
│   └── wrappers/              # Safe system call wrappers
└── lib/                       # External libraries
    ├── libft/                 # Custom C library
    └── dlst/                  # Doubly linked list library
```

### Key Components

- **Lexer**: Tokenizes input into meaningful units
- **Grammar/Parser**: Builds command structures from tokens
- **Expander**: Processes expansions and wildcards
- **Executor**: Runs commands with proper I/O setup
- **Builtins**: Implements shell built-in commands
- **Subsystem**: Manages environment, signals, and utilities
- **Wrappers**: Provides error-checked system call wrappers

## Implementation Details

### Memory Management
- All dynamically allocated memory is properly freed
- Uses custom `ft_malloc` wrapper for error handling
- Implements cleanup functions for all data structures

### Error Handling
- System call wrappers check for errors and handle them appropriately
- Parser provides syntax error messages
- Command execution reports file not found and permission errors

### Process Management
- Uses `fork()` to create child processes
- Uses `execve()` for command execution
- Properly waits for child processes and collects exit status
- Implements pipeline communication using `pipe()`

### File Descriptor Management
- Careful handling of file descriptor duplication and closing
- Proper cleanup of pipe file descriptors
- Restoration of stdin/stdout for built-in commands

## Authors

# Team work 💪

This project was a team effort. You can checkout the team members here:

-   **Pedro Martinez**
    -   [Github](https://github.com/peterm-m)
    -   [LinkedIn](https://www.linkedin.com/in/pedro-martinez-ab5961225/)
    -   [42 intra](https://profile.intra.42.fr/users/pedromar)
-   **Alejandro Díaz-Ufano Pérez**
    -   [Github](https://github.com/adiaz-uf)
    -   [LinkedIn](https://www.linkedin.com/in/alejandro-diaz-ufano/)
    -   [42 intra](https://profile.intra.42.fr/users/adiaz-uf)

## License

This project is part of the 42 School curriculum.

---

**Note**: This is an educational project created for learning purposes. While it implements many shell features, it is not intended for production use.
