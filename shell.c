#include "main.h"

int main(void)
{
	char *buffer;
	size_t bufsize;
	ssize_t read;
	char *str;
        pid_t child;
        char *command[16];
	char *tok;
	char *filepath;
	size_t i;
        int status;

        while (1)
        {
		buffer = NULL;
		bufsize = 0;

		get_input(&buffer, &bufsize, &read);

		str = strdup(buffer);

		free(buffer);

		tok = strtok(str, " \t\n\r");
                i = 0;

		while (i < 16 && tok != NULL)
                {
                        command[i] = tok;
                        tok = strtok(NULL, " \t\n\r");
                        i = i + 1;
                }
                command[i] = NULL;
                child = fork();
                if (child == 0)
		{
			if (strchr(command[0], '/') != NULL)
			{
				if (execve(command[0], command, environ) == - 1)
				{
					perror("Error executing command");
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
						perror("Error executing");
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
	}
	free(str);
	exit(status);
}
