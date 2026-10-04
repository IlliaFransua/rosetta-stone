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

char *copy_str(char *src)
{
	int i;
	char *dup;

	dup = (char *)malloc((len(src) + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (src[i] != '\0') {
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char *copy_str_n(char *src, int n)
{
	int i;
	int size;
	char *dup;

	size = len(src);
	if (n > size)
		n = size;
	dup = (char *)malloc((n + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < n) {
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int ft_strcmp(char *s1, char *s2)
{
	unsigned int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0') {
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
