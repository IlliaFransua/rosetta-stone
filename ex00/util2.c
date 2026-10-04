#include "rush02.h"

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

int equals(char *s1, char *s2)
{
	unsigned int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0') {
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
