# The Shell

**Hewson Trinh and Duncan MacLennan**


## About the project
This is a custom implementation of the shell program that runs most modern command line interfaces.

## Table of Contents
<details>
	<summary>Table of Contents</summary>
	<ul>
	<li>
	<a href="#requirements">Requirements</a>
	</li>
	<li>
	<a href="#repository-contents">Repository Contents</a>
	</li>
	<li>
	<a href="#features">Features</a>
	</li>
	<li>
	<a href="#getting-started">Getting Started</a>
			<ul>
			<li><a href="#installation">Installation</a></li>
			<li><a href="#manual-page">Manual Page</a></li>
			</ul>
	</li>
	<li>
	<a href="#usage">Usage</a>
	<ul>
	<li><a href="#Examples-of-commands">Examples of commands</a></li>
	<li><a href="#Flowchart">Flowchart</a></li>
	<li><a href="#interactive-mode">Interactive Mode</a></li>
	<li><a href="#non-interactive-mode">Non-interactive Mode</a></li>
	</ul>
	</li>
	<li>
	<a href="#authors">Authors</a>
	</li>
	</ul>
</details>

## Requirements

<ul>
<li>Ubuntu 20.04 LTS</li>
	<ul>
		<li><a href="https://ubuntu.com/tutorials/install-ubuntu-on-wsl2-on-windows-11-with-gui-support#1-		overview">Windows 10 or 11</a>
		<li><a href="https://ubuntu.com/download/desktop">Mac</a>
	</ul>
<li>Follows the <a href="https://github.com/alx-tools/Betty/wiki">Betty</a> linter <a href="https://github.com/hs-hq/Betty/blob/main/betty-style.pl">style</a> and <a href="https://github.com/hs-hq/Betty/blob/main/betty-doc.pl">documentation</a></li>
<li>No more than 5 functions per file</li>
</ul>

## Repository Contents

| **File** | **Description**|
|----------|----------------|
|`main.h`| A header file containing the prototype functions and the global variable `environ` |
|`shell.c`| A `C` program that contains the main function |
|`command_shell.c`| A `C` program that contains the function `get_input`, `fork_the_child`, `line_to_array` and `executable_cmd`|
|`find_path.c`| A`C` program that contains the functions `_getenv`, `find_exectuable_in_path`, `string_into_words` and `get_exe_string` |
|`built_in.c`| A`C` program that contains the functions `print_env`, `checkbuiltin`, `_opendir` and `_readdir` |

## Features

- Includes built-in commands `exit` and `env`
	- `exit` closes the shell
	- `env` prints the environment
- Allows for commands to be executed with the `$PATH` environment variable
- Supports both interactive and non-interactive mode
- Basic error handling

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
| `$ pwd` | `/holberton-simple_shell` |
| `$ ls` | `built_in.c  command_shell.c  find_path.c  hsh  main.h  README.md  shell.c` |
| `$ touch holberton_test` `$ ls` | `built_in.c  command_shell.c  find_path.c  holberton_test  hsh  main.h  README.md  shell.c` |
| `$ rm holberton_test` `$ ls` | `built_in.c  command_shell.c  find_path.c  hsh  main.h  README.md  shell.c` |
| `$ which ls` | `/usr/bin/ls` |
| `$ cp main.h mane.h` `$ ls` | `built_in.c  command_shell.c  find_path.c  hsh  main.h  README.md  shell.c  mane.h` |
| `$ mv mane.h /tmp/` `$ ls /tmp/` | `mane.h` |
| `$ mkdir folder` `$ ls` | `built_in.c  command_shell.c  find_path.c  hsh  main.h  README.md  shell.c folder`  |
| `$ wc main.h` | `34 74 736 main.h` |
| `$ exit` | ...closes the shell |

---

## Usage

### Flowchart
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

### Interactive mode
To open the simple shell in the interactive mode type the below:

```
./hsh
```
This will open the simple shell with a prompt `$` and allow the user to input commands. Example:

```
./hsh

$ _enter-your-command-here_
```
Commands can then be entered after the `$` and run, if it is a known command, it will execute, otherwise, an error message will appear.

To close the simple shell:

```
$ exit
```

**Output Examples**

| **User input** | **Expected output**|
|------------|-----------------|
|`/bin/ls` | Lists the contents of the current directory e.g. ``` hsh main.c shell.c ``` |
|`ls` | Lists the contents of the current directory e.g. ``` hsh main.c shell.c ``` |
|`ls -l /tmp`| <pre>-rw-r--r-- 1 root  root  2519 Jun 15 17:44 32 <br>|


### Non-interactive mode

The simple shell does not need to be opened. Commands can be piped into the simple shell executable using `echo`. For example, to run `/bin/ls` in the simple shell in the non-interactive mode, use the below:

```
echo "/bin/ls" | ./hsh
```
Once the process has been executed, there is no need to `exit` as the simple shell does not open in the non-interactive mode.

**Output Examples**

| **User input** | **Expected output**|
|------------|-----------------|
|`echo "/bin/ls" \| ./hsh` | Lists the contents of the current directory e.g. ``` hsh main.c shell.c ``` |
|`echo "ls" \| ./hsh` | Lists the contents of the current directory e.g. ``` hsh main.c shell.c ``` |
|`echo "ls -l /tmp" \| ./hsh`| <pre>-rw-r--r-- 1 root  root  2519 Jun 15 17:44 32 <br>|

# Authors

**Hewson Trinh and Duncan MacLennan**
