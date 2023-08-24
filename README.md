# The Shell

**Hewson Trinh and Duncan MacLennan**



# Repository Contents

`main.h`

`shell.c`

`command_shell.c`

`find_path.c`

`built_in.c`

`README.md`

# Let's get started

To access the custom shell, open terminal (on mac) or Windows Terminal (pc).

Clone the GitHub repo `https://github.com/hewsontrinh526/holbertonschool-simple_shell.git`

Navigate to the folder where you cloned the shell.

Then type into the command line  `./hsh`

### Examples of commands

| Command | Output |
| --- | --- |
| `echo Hello, World` | `Hello, World`  |
| `pwd` | `/folder` |
| `ls` | `built_in.c  command_shell.c  find_path.c  hsh  main.h  README.md  shell.c` |
| `touch testfile` `ls` | `built_in.c  command_shell.c  find_path.c  hsh  main.h  README.md  shell.c testfile` |
| `rm testfile` `ls` | `built_in.c  command_shell.c  find_path.c  hsh  main.h  README.md  shell.c` |
| `which ls` | `/usr/bin/ls` |
| `cp main.h mane.h` `ls` | `built_in.c  command_shell.c  find_path.c  hsh  main.h  README.md  shell.c  mane.h` |
| `mv mane.h /tmp/` `ls /tmp/` | `mane.h` |
| `mkdir folder` `ls` | `built_in.c  command_shell.c  find_path.c  hsh  main.h  README.md  shell.c folder`  |
| `wc main.h` | `34 74 736 main.h` |

---
![Simple Shell - Frame 3](https://github.com/hewsontrinh526/holbertonschool-simple_shell/assets/135479331/688fac6a-b0b1-4f46-9e89-8d0447a61195)

##### Flowchart of Simple Shell

1. After starting, the shell decides if its in interactive mode or non-interactive mode. 
2. If in interactive mode, the shell will display its prompt `$` .
3. After the user types an input, the shell will read it and decide what to do with it.
4. If its not a valid command, it will print an error message.
5. If it **is** valid, it will check if it is one of the built-in commands, `env` or `exit` .
6. If `env` it will print the current environment. If `exit` it will exit the shell.
7. If it is ****not**** one of the built-in commands, it will check if the command exists.
8. If so, it will split the process into child and parent processes and execute the command.

# Authors

**Hewson Trinh and Duncan MacLennan**
