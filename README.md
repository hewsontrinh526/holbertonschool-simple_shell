# The Shell

**Hewson Trinh and Duncan MacLennan**


## About the project
This is a custom implementation of the shell program that runs most modern command line interfaces.

## Table of Contents
<details>
	<summary>Table of Contents</summary>
	<ul>
	<li>
	<a href="#repository-contents">Repository Contents</a>
	</li>
	<li>
	<a href="#getting-started">Getting Started</a>
			<ul>
			<li><a href="#installation">Installation</a></li>
			<li><a href="#manual-page">Manual Page</a></li>
			</ul>
	</li>
	<li><a href="#Examples-of-commands">Examples of commands</a></li>
	<li><a href="#Flowchart">Flowchart</a></li>
	<li>
	<a href="#authors">Authors</a>
	</li>
	</ul>
</details>

# Repository Contents

`main.h`

`shell.c`

`command_shell.c`

`find_path.c`

`built_in.c`

`README.md`

## Getting Started

To access the custom shell, open terminal (on mac) or Windows Terminal (pc).
### Installation

Clone the GitHub repo `https://github.com/hewsontrinh526/holbertonschool-simple_shell.git`

Navigate to the folder where you cloned the shell.

Enter this command to compile:

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

Then type into the command line  `./hsh` to launch the shell

### Manual page

Call the manual to read how the `simple shell` works:

```
man ./man_1_simple_shell
```


### Examples of commands

| Command | Output |
| --- | --- |
| `$ echo Hello, World` | `Hello, World`  |
| `$ pwd` | `/folder` |
| `$ ls` | `built_in.c  command_shell.c  find_path.c  hsh  main.h  README.md  shell.c` |
| `$ touch testfile` `$ ls` | `built_in.c  command_shell.c  find_path.c  hsh  main.h  README.md  shell.c testfile` |
| `$ rm testfile` `$ ls` | `built_in.c  command_shell.c  find_path.c  hsh  main.h  README.md  shell.c` |
| `$ which ls` | `/usr/bin/ls` |
| `$ cp main.h mane.h` `$ ls` | `built_in.c  command_shell.c  find_path.c  hsh  main.h  README.md  shell.c  mane.h` |
| `$ mv mane.h /tmp/` `$ ls /tmp/` | `mane.h` |
| `$ mkdir folder` `$ ls` | `built_in.c  command_shell.c  find_path.c  hsh  main.h  README.md  shell.c folder`  |
| `$ wc main.h` | `34 74 736 main.h` |
| `$ exit` | ...closes the shell |

---
## Flowchart
![Simple Shell - Frame 3](https://github.com/hewsontrinh526/holbertonschool-simple_shell/assets/135479331/688fac6a-b0b1-4f46-9e89-8d0447a61195)

##### Flowchart of Simple Shell



**Step One**:
After starting, the shell decides if its in interactive mode or non-interactive mode. 

**Step Two**:
If in interactive mode, the shell will display its prompt `$` .

**Step Three**:
After the user types an input, the shell will read it and decide what to do with it.

**Step Four**:
If its not a valid command, it will print an error message.

**Step Five**:
If it **is** valid, it will check if it is one of the built-in commands, `env` or `exit` .

**Step Six**:
If `env` it will print the current environment. If `exit` it will exit the shell.

**Step Seven**:
If it is ****not**** one of the built-in commands, it will check if the command exists.

**Step Eight**:
If so, it will split the process into child and parent processes and execute the command.


# Authors

**Hewson Trinh and Duncan MacLennan**