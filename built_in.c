#include "main.h"

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


int checkbuiltin(char **array, int *status, char *str)
{
	if (array[0] == NULL)
	{
		free(str);
		return (1);
	}
	if (strcmp(array[0], "exit") == 0)
	{
		free(array);
		exit(*status);
	}
	else if (strcmp(array[0], "env") == 0)
	{
		print_env();
		free(str);
		return (1);
	}
	return (0);
}
