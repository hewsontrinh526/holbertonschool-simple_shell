#include "main.h"

int exit_shell(void)
{
	return (2);
}

int print_env(void)
{
	int i;

	i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i = i + 1;
	}
	return (0);
}


int check_built_in(char **array)
{
	int i;

	if (strcmp(array[0], "exit") == 0)
	{
		i = exit_shell();
		return (i);
	}
	else if (strcmp(array[0], "env") == 0)
	{
		i = print_env();
		return (i);
	}
	return (1);
}
