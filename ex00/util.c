#include "rush02.h"

int is_printable(char c)
{
	return (' ' <= c && c <= '~');
}

int is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

void print(char *str)
{
	while (*str != '\0') {
		write(1, str, 1);
		str++;
	}
}

int len(char *str)
{
	int index;

	index = 0;
	while (str[index] != '\0') {
		index++;
	}
	return (index);
}

int is_numeric(char c)
{
	return ('0' <= c && c <= '9');
}

int compare_str(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0') {
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (s1[i] != '\0')
		return (s1[i]);
	else if (s2[i] != '\0')
		return (-s2[i]);
	return (0);
}
