#include "shell.h"

/**
 * print_number - function that prints an integer
 * @n: integer to print
*/
void print_number(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n == 0)
		write(1, "0", 1);
	else
	{
		char str[12];
		int i = 0;

		while (n != 0)
		{
			str[i] = (n % 10) + '0';
			n /= 10;
			i++;
		}
		str[i] = '\0';
		for (i = i - 1; i >= 0; i--)
			write(1, &str[i], 1);
	}
}
/**
 * _strcat -> function that concatenates two strings
 * @dest: pointer to string
 * @src: pointer to string
 * Return: dest
 */
char *_strcat(char *dest, char *src)
{
	int len = 0;
	int i;

	while (dest[len] != '\0')
	{
		len++;
	}
	for (i = 0; src[i] != '\0'; i++)
		dest[len + i] = src[i];
	dest[len + i] = '\0';
	return (dest);
}

/**
 * _strlen -> function that returns the length of a string.
 * @s: pointer to a string
 * Return: length of a string
 */
int _strlen(char *s)
{
	int len = 0;
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

/**
 * _strcpy - function that copies the string pointed to by src
 * @src: pointer to string
 * @dest: pointer to string
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int len = 0;
	int i = 0;

	while (src[len] != '\0')
		len++;
	while (i < (len + 1))
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
