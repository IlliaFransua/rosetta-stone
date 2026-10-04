#include "rush02.h"

static void	ft_cleanup(int fd, t_node *dictionary)
{
	t_node	*curr_node;
	t_node	*node_to_clean;

	// ALSO CLEAN NUM AND EVERYTHING ELSE UP TO THE END
	// ALSO CHECK ALL STRDUP STRCPY STRNDUP
	// CLEANUP THE WORDS LIST!!!

	curr_node = dictionary;
	while (curr_node != NULL)
	{
		node_to_clean = curr_node;
		curr_node = curr_node->next;
		free(node_to_clean->dict_entry.key);
		free(node_to_clean->dict_entry.value);
		free(node_to_clean);
	}
	close(fd);
	return ;
}

static int	ft_get_number(char *num, t_node *dictionary, int i
	, t_word_node **words_head) 
{
	int	relative_pos;
	int	pos;
	char	*word;
	char	key_dict[3];

	pos = ft_strlen(num) - i - 1;
	relative_pos = i % 3;
	if (relative_pos == 0 && i > 0)
	{
		if (!ft_get_ten_power(dictionary, words_head, num, i))
			return (0);
	}
	if (relative_pos == 2)
		return (ft_get_hundreds(dictionary, words_head, num[pos]));
	if (relative_pos == 1)
		return(ft_get_tens(dictionary, words_head, num[pos], num[pos + 1]));
	if (relative_pos == 0)
		return(ft_get_units(dictionary, words_head, num, pos));
	return (1);
}

static int	ft_convert_number(char *clean_num, t_node *dictionary)
{
	int	len;
	t_word_node	*words_head;
	int	max_word_len;
	int	i;

	words_head = NULL;
	len = ft_strlen(clean_num);
	i = 0;
	while (i < len)
	{
		ft_get_number(clean_num, dictionary, i, &words_head);
		i++;
	}
	ft_print_words(words_head);
	free(words_head);			// WATCH OUT FOR FREEING ON ERROR TOO!!
	return (1);
}

void	ft_convert_number_rosetta(char *filename, char *num)
{
    char	*clean_num = "1000000";
	int	fd;
	t_node	*dictionary;

	// clean_num = ft_validate_number(num);
	// if (!clean_num)
	// {
	// 	ft_putstr("Error\n");
	// 	return ;
	// }
	fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
		ft_putstr("Dict Error\n");
		return ;
    }
	if (ft_parse_dictionary(fd, &dictionary))
	{
		if (!ft_convert_number(clean_num, dictionary))
			ft_putstr("Dict Error\n");
	}
	else
		ft_putstr("Dict Error\n"); // AND CLEAN RESOURCES
	ft_cleanup(fd, dictionary);
	return ;
}