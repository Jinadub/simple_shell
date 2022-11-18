#include "shell.h"

/**
 * prompt - prompt the user for input
 * @state: check the state
 * Return: none
 */
void prompt(int state)
{
	char *buffer = NULL;

	if (state == 1)
		write(1, "My shell : ", 11);


	buffer = _getline();

	if (state == 1)
		tokenizer(buffer, 1);
	else
		tokenizer(buffer, 2);
}
