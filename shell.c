#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
        pid_t child;
        char *argv[100], *tok, *lineptr = NULL;
        size_t i;
	size_t n;
	ssize_t read;
        int status;

        while (1)
        {
		if (isatty(STDIN_FILENO) == 1)
		{
			printf("$ ");
		}

		read = getline(&lineptr, &n, stdin);

		if (read == -1)
                {
                        break;
                }

		tok = strtok(lineptr, " \t\n\r");
                i = 0;

		while (i < 100 && tok != NULL)
                {
                        argv[i] = tok;
                        tok = strtok(NULL, " \t\n\r");
                        i = i + 1;
                }

		argv[i] = NULL;
                child = fork();

		if (child == 0)
                {
                        if (execve(argv[0], argv, NULL) == -1)
                        {
                                exit(EXIT_FAILURE);
                        }
                }
                if (child > 0)
                {
                        wait(&status);
                }
	}
	free(lineptr);
        exit(status);
}
