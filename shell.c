#include "main.h"

int main(void)
{
	char *buffer;
	size_t bufsize;
	ssize_t read;
        char **command;
	char *str;
	int built_in_checker;
	int *status;

	status = malloc(sizeof(int));

	*status = 0;

        while (1)
        {
		buffer = NULL;
		bufsize = 0;

		get_input(&buffer, &bufsize, &read);

		str = strdup(buffer);
		free(buffer);

		command = malloc(2048);

		line_to_array(str, command);

		built_in_checker = checkbuiltin(command, environ, str, status);

		if (built_in_checker == 1)
		{
			continue;
		}

		fork_the_child(command, environ, &str, status);

		free(command);
		free(str);
	}
	exit(*status);
}
