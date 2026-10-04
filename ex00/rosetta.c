#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "rush02.h"

void cleanup(int fd, t_node *dictionary)
{
	t_node *curr_node;
	t_node *node_to_clean;

	curr_node = dictionary;
	while (curr_node != NULL) {
		node_to_clean = curr_node;
		curr_node = curr_node->next;
		free(node_to_clean->dict_entry.key);
		free(node_to_clean->dict_entry.value);
		free(node_to_clean);
	}
	if (fd >= 0)
		close(fd);
}

static int get_number(char *num, t_node *dictionary, int i,
					  t_word_node **words_head)
{
	int relative_pos;
	int pos;

	pos = len(num) - i - 1;
	relative_pos = i % 3;
	if (relative_pos == 0 && i > 0) // HZ
	{
		if (!ft_get_ten_power(dictionary, words_head, num, i))
			return (0);
	}
	if (relative_pos == 2)
		return (ft_get_hundreds(dictionary, words_head, num[pos]));
	if (relative_pos == 1)
		return (ft_get_tens(dictionary, words_head, num[pos], num[pos + 1]));
	if (relative_pos == 0)
		return (ft_get_units(dictionary, words_head, num, pos));
	return (1);
}

static int convert_num_to_words(char *clean_num, t_node *dictionary)
{
	int size;
	t_word_node *words_head;
	int i;

	words_head = NULL;
	size = len(clean_num);
	i = 0;
	while (i < size) {
		if (!get_number(clean_num, dictionary, i, &words_head)) {
			ft_cleanup_word_list(words_head);
			return (0);
		}
		i++;
	}
	ft_print_words(words_head);
	ft_cleanup_word_list(words_head);
	return (1);
}

void convert_number(char *filename, char *num)
{
	char *clean_num;
	int fd;
	t_node *dictionary;

	dictionary = NULL;
	clean_num = clean_number(num);
	if (!clean_num) {
		print("Error\n");
		return;
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0) {
		print("Dict Error\n");
		return;
	}
	if (parse_dictionary(fd, &dictionary)) {
		if (!convert_num_to_words(clean_num, dictionary))
			print("Dict Error\n");
	} else
		print("Dict Error\n");
	cleanup(fd, dictionary);
}
