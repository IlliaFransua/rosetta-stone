#include "rush02.h"

int	ft_push_front(t_word_node **words_head, char *str)
{
	t_word_node	*new_node;

	if (!str)
		return (0);
	new_node = (t_word_node *) malloc(sizeof(t_word_node));
	if (!new_node)
		return (0);
	new_node->str = str;
	new_node->next = *words_head;
	*words_head = new_node;
	return (1);
}

void	ft_print_words(t_word_node *words_head)
{
	t_word_node	*curr_node;

	curr_node = words_head;
	while (curr_node != NULL)
	{
		ft_putstr(curr_node->str);
		curr_node = curr_node->next;
	}
}

char	*ft_make_key(char *buf, char c1, char c2)
{
	buf[0] = c1;
	buf[1] = c2;
	if (c2 != '\0')
		buf[2] = '\0';
	return (buf);
}

int	ft_get_hundreds(t_node *dict, t_word_node **words_head, char digit)
{
	char	*word;
	char	*key[2];
	
	word = ft_search_dict(dict, "100");
	if (!word)
		return (0);
	if (!ft_push_front(words_head, word));
		return (0);
	key[0] = digit;
	key[1] = '\0';
	if (!ft_push_front(words_head, ft_search_dict(dict, key)))
		return (0);
	return (1);
}

int	ft_get_tens(t_node *dict, t_word_node **words_head, char ten, char unit)
{
	char	key[3];

	if (ten == '0')
		return (1);
	if (ten == '1')
	{
		key[0] = '1';
		key[1] = unit;
		key[2] = '\0';
		return (ft_push_front(words_head, ft_search_dict(dict, key)));
	}
	key[0] = ten;
	key[1] = '0';
	key[2] = '\0';
	return (ft_push_front(words_head, ft_search_dict(dict, key)));
}

int	ft_get_units(t_node *dict, t_word_node **words_head, char *num, int pos)
{
	char	key[2];

	if (num[pos] == '0')
	{
		if (ft_strlen(num) == 1)
			return (ft_push_front(words_head, ft_search_dict(dict, "0")));
		return (1);
	}
	if (pos > 0 && num[pos - 1] == '1')
		return (1);
	key[0] = num[pos];
	key[1] = '\0';
	return (ft_push_front(words_head, ft_search_dict(dict, key)));
}