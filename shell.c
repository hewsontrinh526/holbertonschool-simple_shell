#include "main.h"

int main(void)
{
	char *buffer;
	size_t bufsize;
	ssize_t read;
	int exit_status;
        char **command;
	char *str;

        while (1)
        {
		buffer = NULL;
		bufsize = 0;

		get_input(&buffer, &bufsize, &read);

		str = strdup(buffer);
		free(buffer);

		command = malloc(2048);

		line_to_array(str, command);

		exit_status = fork_the_child(command, environ, &str);
		free(command);
		free(str);
	}
	exit(exit_status);
}
