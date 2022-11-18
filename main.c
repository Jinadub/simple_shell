#include "shell.h"

/**
 * main - entry point
 * Return: int
 */
int main(void)
{

	if (isatty(STDIN_FILENO) == 0)
	{
		prompt(2);
	}

	prompt(1);
	return (0);
}
