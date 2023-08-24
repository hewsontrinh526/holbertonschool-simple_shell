#include "main.h"

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

int fork_the_child(char **command, char **environ, char **str, int *status)
{
	pid_t child;
	char *filepath;
	int fork_status;
	int exit_status = 1;

	child = fork();

	if (child == -1)
	{
		printf("./hsh: 1: %s: not found\n", command[0]);
		*status = 2;
		exit(EXIT_FAILURE);
	}
	else if (child == 0)
	{
		if (strchr(command[0], '/') != NULL)
		{
			if (execve(command[0], command, environ) == -1)
			{
				perror("Error executing command");
				free(command);
				free(*str);
				*status = 2;
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			filepath = find_executable_in_path(command[0]);
			if (filepath != NULL)
			{
				if (execve(filepath, command, environ) == -1)
				{
					perror("Error executing command");
					free(command);
					free(*str);
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				printf("%s: command not found\n", command[0]);
				free(command);
				exit (127);
			}
		}
	}
	else
	{
		wait(&fork_status);
		if (WIFEXITED(fork_status))
		{
			exit_status = WEXITSTATUS(fork_status);
		}
	}
	return (exit_status);
}

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
