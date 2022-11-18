#include "shell.h"

/**
 * tokenizer - tokenize the buffer
 * @buffer: input from user
 * @state: use to track state
 * Return: void
 */
void tokenizer(char *buffer, int state)
{
	char *copy = NULL,  *token = NULL;
	char **argv = NULL;
	struct stat st;
	int argc = 0, i = 0;

	copy = malloc(sizeof(char) * _strlen(buffer));
	if (copy == NULL)
	{
		free(buffer);
		exit(0);
	}
	_strcpy(copy, buffer);
	token = strtok(buffer, " \n");

	while (token)
	{
		token = strtok(NULL, " \n");
		argc++;
	}
	argv = malloc(sizeof(char *) * argc);
	if (argv == NULL)
	{
		free(buffer);
		exit(0);
	}
	token = strtok(copy, " \n");
	while (token)
	{
		argv[i] = token;
		token = strtok(NULL, " \n");
		i++;
	}
	argv[i] = NULL;
	free(buffer);
	if (argv[0][0] == '/' && stat(copy, &st) == 0)
	{
		exec(argv, copy, state);
	}

	find(argv, copy, state);
}
