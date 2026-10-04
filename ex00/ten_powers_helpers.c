#include "rush02.h"

static int	ft_is_triplet_nonzero(char *num, int pos)
{
	if (num[pos] != '0')
		return (1);
	if (pos > 0 && num[pos - 1] != '0')
		return (1);
	if (pos > 1 && num[pos - 2] != '0')
		return (1);
	return (0);
}

static char	*ft_make_ten_key(char *key, int zeroes)
{
	int	i;

	key[0] = '1';
	i = 1;
	while (i <= zeroes)
	{
		key[i] = '0';
		i++;
	}
	key[i] = '\0';
	return (key);
}

int	ft_get_ten_power(t_node *dict, t_word_node **words_head, char *num, int i)
{
	char	key[80];
	int	pos;

	pos = ft_strlen(num) - i - 1;
	if (ft_is_triplet_nonzero(num, pos))
	{
		if (!ft_push_front(words_head
			, ft_search_dict(dict, ft_make_ten_key(key, i))))
			return (0);
	}
	return (1);
}