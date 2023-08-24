#include "main.h"

int print_env(char **array)
{
	int i;

	i = 0;

	while (array[i] != NULL)
	{
		printf("%s\n", array[i]);
		i = i + 1;
	}
	return (0);
}


int checkbuiltin(char **array, char **environ, char *str, int *status)
{
	if (array[0] == NULL)
	{
		free(str);
		return (1);
	}
	if (strcmp(array[0], "exit") == 0)
	{
		free(str);
		exit(*status);
	}
	else if (strcmp(array[0], "env") == 0)
	{
		print_env(environ);
		free(str);
		return (1);
	}
	return (0);
}

DIR *_opendir(char *name)
{
	DIR *dp;

	dp = opendir(name);

	if (dp == NULL)
	{
		perror("open directory");
		return (NULL);
	}
	return (dp);
}

struct dirent *_readdir(DIR *dp)
{
	struct dirent *ep;

	ep = readdir(dp);

	if (ep == NULL)
	{
		return (NULL);
	}
	return (ep);
}
