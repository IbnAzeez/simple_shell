/**
 * _strn_cmp - compares two strings up to n length
 * @s: string to search for
 * @var: variable to compare against
 * @n: length to compare up to
 * Return: 1 if strings are equal, -1 if they are not
 */
int _strn_cmp(char *s, char *var, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		if (s[i] != var[i])
			return (-1);
		i++;
	}
	return (1);
}
