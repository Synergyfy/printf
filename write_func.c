#include <unistd.h>
#include <stdio.h>

/**
 * _putchar - write character to stdout
 * @c: character
 * Return: 1 on success
 * Description: Use a local buffer of 1024 chars in order to call write as
 * little as possible.
 */
int _putchar(char c)
{
	static char buffer[1024];
	static int i;
	
	if (c == -1 || i >=1024)
	{
		write(1, &buffer, i);
		i = 0;
	}
	if (c != -1)
	{
		buffer[i] = c;
		i++;
	}
	return (1);
}
/**
 * _put - print a string
 * @p: pointer to the string
 * Return: number of chars
 */

int _put(char *p)
{
	int i;

	for (i = 0; p[i] != '\0'; i++)
		_putchar(p[i]);
	return (i);
}
