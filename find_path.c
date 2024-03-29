#include "main.h"

/**
 * _getenv - Searches for the environment variable with the given name
 * and returns its value after the equal sign (=).
 *
 * @name: A string representing the name of the environment variable.
 *
 * Return: Pointer to the value of the environment variable if found, NULL
 * if the environment variable is not found.
 */
char *_getenv(char *name)
{
	int i;
	int n;
	char *string;

	i = 0;
	n = strlen(name);

	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], name, n) == 0)
		{
			string = strchr(environ[i], '=');
			return (string);
		}
		i = i + 1;
	}
	return (NULL);
}

/**
 * find_executable_in_path - Searches for an executable file in the
 * directories specified by the PATH environment variable.
 *
 * @cmd: A pointer to the command name string.
 * @prog_av: A string representing the name of the program calling this
 * function (used for error messages).
 *
 * Return: File path name as a string, else NULL.
 */
char *find_executable_in_path(char **cmd, char *prog_av)
{
	char *path, *dir, *each_path[100];
	int i;
	DIR *dp;
	struct dirent *ep = NULL;

	path = strdup(_getenv("PATH="));
	if (path == NULL)
	{
		fprintf(stderr, "%s: %s: %s: not found\n", prog_av, "1", *cmd);
		return (NULL);
	}

	dir = strdup(path + 1);
	string_into_words(dir, each_path);
	i = 0;

	while (each_path[i] != NULL && i < 99)
	{
		dp = _opendir(each_path[i]);
		ep = _readdir(dp);

		while (ep != NULL)
		{
			if (strcmp(*cmd, ep->d_name) == 0)
			{
				*cmd = get_exe_string(each_path[i], ep->d_name);
				free(dir);
				free(path);
				closedir(dp);
				return (*cmd);
			}
			ep = _readdir(dp);
		}
		closedir(dp);
		i = i + 1;
	}
	free(dir);
	free(path);
	fprintf(stderr, "%s: %s: %s: not found\n", prog_av, "1", *cmd);
	return (NULL);
}

/**
 * string_into_words - Tokenizes a given string into an array of
 * words, splitting it by colons (:).
 *
 * @string: A string representing the text to be tokenized.
 * @words: A pointer to the array where the tokenized words will be stored.
 *
 * Return: void.
 */
void string_into_words(char *string, char **words)
{
	char *word;
	int i;

	i = 0;
	word = strtok(string, ":");

	while (word != NULL && i < 99)
	{
		words[i] = word;
		i = i + 1;
		word = strtok(NULL, ":");
	}
	words[i] = NULL;
}

/**
 * get_exe_string - Constructs and returns the full path to an executable
 * by concatenating the directory path with the executable name.
 *
 * @path: A string representing the directory path.
 * @program_av: A string representing the name of the executable.
 *
 * Return: Pointer to the full path of the executable if successful, NULL
 * if memory allocation fails.
 */
char *get_exe_string(char *path, char *program_av)
{
	char *string;
	size_t size;

	size = sizeof(*string) * (strlen(program_av) + 2 + strlen(path));
	;
	string = (char *)malloc(size);

	if (string == NULL)
	{
		perror("malloc");
		return (NULL);
	}
	string[0] = '\0';
	strcat(string, path);
	strcat(string, "/");
	strcat(string, program_av);
	return (string);
}
