#include "main.h"

int main(void)
{
	char *buffer;
	size_t bufsize;
	ssize_t read;
	char *str;
	int exit_status;
        char *command[16];
	char *tok;
	size_t i;

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

		exit_status = fork_the_child(command, environ, &str);
	}
	free(str);
	exit(exit_status);
}
