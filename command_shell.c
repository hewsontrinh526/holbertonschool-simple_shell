#include "main.h"

void get_input(char **buffer, size_t *bufsize, ssize_t *read)
{
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

int fork_the_child(char **command, char **environ, char **str)
{
	pid_t child;
	char *filepath;
	int status;

	child = fork();

	if (child == 0)
	{
		if (strchr(command[0], '/') != NULL)
		{
			if (execve(command[0], command, environ) == -1)
			{
				perror("Error executing command");
				free(str);
				exit(127);
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
					free(str);
					exit(127);
				}
			}
			else
			{
				printf("%s: command not found\n", command[0]);
				return (-1);
			}
		}
	}
	if (child > 0)
	{
		wait(&status);
	}
	return (status);
}
