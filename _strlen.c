
/**
 * _strlen - returns the length of a string.
 * @str: Characters
 * Return: Always 0.
 */

int _strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
