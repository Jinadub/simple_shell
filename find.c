#include "shell.h"
void free_all(char *copy, char **env_cpy, char *path);

/**
 * find - find path and execute
 * @argv: char array of input
 * @copy: copy of buffer
 * @state: keep track of state
 * Return: void
 */
void find(char **argv, char *copy, int state)
{
	int i = 0;
	char *token = NULL, *key = "PATH", *path = NULL, *msg = ": not found\n", *g;
	char **env_cpy;
	struct stat st;

	if (strcmp(argv[0], "exit") == 0)
	{
		if (argv[1])
			exit(_atoi(argv[1]));
		exit(0);
	}
	while (environ[i])
		i++;
	env_cpy = malloc(sizeof(char *) * i);
	for (i = 0; environ[i]; i++)
		env_cpy[i] = strdup(environ[i]);
	env_cpy[i] = NULL;
	i = 0;
	while (env_cpy[i])
	{
		token = strtok(env_cpy[i++], "=");
		if (strcmp(key, token) == 0)
			break;
	}
	token = strtok(NULL, "\0");
	token = strtok(token, ":");
	while (token)
	{
		path = malloc(sizeof(char) * (strlen(token) + strlen(copy) + 1));
		strcat(path, token), strcat(path, "/"), strcat(path, copy);
		if (stat(path, &st) == 0)
		{
			argv[0] = strdup(path);
			exec(argv, copy, state);
		}
		token = strtok(NULL, ":");
	}
	g = _strcat(argv[0], msg);
	write(1, g, _strlen(g));
	free_all(copy, env_cpy, path);
}

/**
 * free_all - free allocated spaces and call prompt again
 * @copy: par 1
 * @env_cpy: par 2
 * @path: par 3
 * Return: void
 */
void free_all(char *copy, char **env_cpy, char *path)
{
	free(copy);
	free(env_cpy);
	free(path);
	prompt(1);
}
