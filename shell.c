#include "main.h"

int main(__attribute__((unused)) int ac, char *av[])
{
	char *buffer;
	size_t bufsize;
	ssize_t read;
        char *cmd[124];
	char *str;
	int built_in_checker;
	int exit_status;
	int status;
	int k;

	status = 0;

	while (1)
        {
		buffer = NULL;
		bufsize = 0;
		k = 0;

		get_input(&buffer, &bufsize, &read);

		str = strdup(buffer);
		free(buffer);

		line_to_array(str, cmd);

		built_in_checker = checkbuiltin(cmd, environ, str, &status);

		if (built_in_checker == 1)
		{
			continue;
		}
		if (executable_cmd(cmd[0]) == 0)
		{
			cmd[0] = find_executable_in_path(&(cmd[0]), av[0]);
			k = 1;

			if (cmd[0] == NULL)
			{
				free(str);
				return (127);
			}
		}

		exit_status = fork_the_child(cmd, environ, &str);

		if (k == 1)
		{
			free(cmd[0]);
		}
		free(str);
	}
	exit(exit_status);
}
