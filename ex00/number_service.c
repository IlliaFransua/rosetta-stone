#include "rush02.h"

int is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char *clean_number(char *str)
{
	int i;
	int start;

	i = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-')
		return (NULL);
	if (str[i] == '+')
		i++;
	if (!('0' <= str[i] && str[i] <= '9'))
		return (NULL);
	while (str[i] == '0' && '0' <= str[i + 1] && str[i + 1] <= '9')
		i++;
	start = i;
	while (str[i]) {
		if (!('0' <= str[i] && str[i] <= '9'))
			return (NULL);
		i++;
	}
	return (&str[start]);
}
