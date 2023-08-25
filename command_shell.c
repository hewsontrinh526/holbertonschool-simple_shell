#include "main.h"

/**
 * get_input - Reads a line of input from the standard input, displaying
 * a prompt if the input is a terminal.
 *
 * @buffer: A pointer to the buffer where the input will be stored.
 * @bufsize: A pointer to the size of the buffer.
 * @read: A pointer to a variable that stores the number of characters read.
 *
 * Return: Void
 */
void get_input(char **buffer, size_t *bufsize, ssize_t *read)
{
	signal(SIGINT, SIG_IGN);
	if (isatty(0) == 1)
	{
		printf("$ ");
	}

	*read = getline(buffer, bufsize, stdin);
	fflush(stdin);

	if (*read == -1)
	{
		free(*buffer);
		exit(EXIT_SUCCESS);
	}
}

/**
 * fork_the_child - Forks a child process to execute
 * a given command using execve.
 *
 * @command:  An array of strings representing the command and its arguments.
 * @environ: An array of strings representing the environment variables.
 * @str: A pointer to a string that may be associated with the command and
 * is freed if execve fails.
 * @status: A pointer to an integer representing the child's exit
 * status or termination signal.
 *
 * Return: The exit status or termination signal of the child process.
 */
int fork_the_child(char **command, char **environ, char **str, int *status)
{
	int child;
	int wait_status;

	child = fork();

	if (child == 0)
	{
		if (execve(command[0], command, environ) == -1)
		{
			printf("EXECVE FAIL\n");
			free(*str);
			exit(*status);
		}
	}
	else
	{
		waitpid(child, &wait_status, 0);

		if (WIFEXITED(wait_status))
		{
			*status = WEXITSTATUS(wait_status);
		}
		else if (WIFSIGNALED(wait_status))
		{
			*status = WTERMSIG(wait_status);
		}
	}
	return (*status);
}

/**
 * line_to_array - Tokenizes a command line string into an array
 * of strings, splitting it by whitespace characters.
 *
 * @str: A string representing the command line input.
 * @command: A pointer to the array where the tokenized command
 * arguments will be stored.
 *
 * Return: Void
 */
void line_to_array(char *str, char **command)
{
	int i;
	const char *delim;
	char *token;

	i = 0;
	delim = " \t\n\r";
	token = strtok(str, delim);

	while (token != NULL)
	{
		command[i] = token;
		token = strtok(NULL, delim);
		i = i + 1;
	}
	command[i] = NULL;
}

/**
 * executable_cmd - Checks if a given file (represented by the string) is
 * executable by the user.
 *
 * @string: A string representing the path to the file to be checked.
 *
 * Return: 1 if the file is executable, 0 if the file is not executable
 * or does not exist.
 */
int executable_cmd(char *string)
{
	struct stat st;

	if (stat(string, &st) == 0 && st.st_mode & S_IXUSR)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
