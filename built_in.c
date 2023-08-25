#include "main.h"
/**
 * print_env - Prints the environment variables to the standard output.
 * @array: An array of strings representing the environment variables.
 * Return: 0 indicating successful execution.
 */
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
/**
 * checkbuiltin - Checks if a given command is a built-in shell command
 * @array: An array of strings representing the command and its arguments.
 * @environ: An array of strings representing the environment variables.
 * @str: A string that may be associated with the command, and is freed if a built-in command is found.
 * @status: A pointer to an integer representing the exit status.
 * Return: 1 if a built-in command is executed, 0 if the command is not a built-in command.
 */
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
/**
 * _opendir - Opens a directory with the given name and returns a pointer to the directory stream.
 * @name: A string representing the name of the directory to be opened.
 * Return: Pointer to the directory stream on success. NULL if the directory could not be opened.
 */
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
/**
 * _readdir - Reads a directory entry from the directory stream pointed to by dp using the readdir function.
 * @dp: A pointer to a directory stream.
 * Return: Pointer to the directory entry structure if an entry is read. NULL if there are no more entries or an error occurs.
 */
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
