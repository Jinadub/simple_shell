#include "shell.h"
/**
 *_strcpy - copies the string pointed to by src
 *@dest: A pointer to a char that will be changed
 *@src: A pointer to a char that will be changed
 *Return: dest
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
	dest[i] = src[i];
	i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strlen - func to check length of string
 * Description: print length of strings
 * @s: character to check its length
 * Return: length of the string
 */
int _strlen(char *s)
{
	int a = 0;

	while (s[a] != '\0')
	{
		a++;
	}
	return (a);
}

/**
 * _atoi - convert string to curr int value
 * @s: string to convert
 * Return: converted int value
 */
int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}


/**
 * _strcat - concatenate two strings
 * @dest: destination
 * @src: source
 * Return: pointer to destination
 */

char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
