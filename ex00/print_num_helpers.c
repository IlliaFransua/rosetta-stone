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
	int i;
	t_word_node	*curr_node;

	i = 0;
	curr_node = words_head;
	while (curr_node != NULL)
	{
		if (i > 0)
			ft_putstr(" ");
		ft_putstr(curr_node->str);
		curr_node = curr_node->next;
		i++;
	}
}

void	ft_cleanup_word_list(t_word_node *words_head)
{
	t_word_node	*curr_node;

	while (words_head != NULL)
	{
		curr_node = words_head->next;
		free(words_head);
		words_head = curr_node;
	}
	return ;
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