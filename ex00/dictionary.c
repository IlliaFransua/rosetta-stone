#include <unistd.h>
#include <stdlib.h>
#include "rush02.h"

int read_line(int fd, char *buffer, int buffer_size)
{
	int i;
	int bytes_read;
	char c;

	i = 0;
	while ((bytes_read = read(fd, &c, 1)) > 0 && c != '\n') {
		if (i < buffer_size - 1) {
			buffer[i] = c;
			i++;
		}
	}
	buffer[i] = '\0';
	if (bytes_read < 0)
		return (-1);
	if (bytes_read == 0 && i == 0)
		return (0);
	return (1);
}

int get_val_len(char *buffer)
{
	int i;

	i = 0;
	while (is_printable(buffer[i]))
		i++;
	if (buffer[i] != '\0')
		return (0);
	while (i > 0 && buffer[i - 1] == ' ')
		i--;
	return (i);
}

int parse_key(char *buffer, int *i, t_node *new_node)
{
	int key_start;
	int key_len;

	while (is_space(buffer[*i]))
		(*i)++;
	if (buffer[*i] == '+')
		(*i)++;
	key_start = *i;
	while (is_numeric(buffer[*i]))
		(*i)++;
	key_len = *i - key_start;
	while (buffer[*i] == ' ')
		(*i)++;
	if (key_len == 0 || buffer[*i] != ':')
		return (0);
	(*i)++;
	new_node->dict_entry.key = copy_str_n(&buffer[key_start], key_len);
	if (!new_node->dict_entry.key)
		return (0);
	return (1);
}

int parse_value(char *buffer, int i, t_node *new_node)
{
	int start_val;
	int val_len;

	while (buffer[i] == ' ')
		i++;
	start_val = i;
	val_len = get_val_len(&buffer[start_val]);
	if (val_len == 0)
		return (0);
	new_node->dict_entry.value = copy_str_n(&buffer[start_val], val_len);
	if (!new_node->dict_entry.value)
		return (0);
	return (1);
}

int parse_line(char *buffer, t_node *new_node)
{
	int i;

	i = 0;
	if (!parse_key(buffer, &i, new_node))
		return (0);
	if (!parse_value(buffer, i, new_node)) {
		free(new_node->dict_entry.key);
		new_node->dict_entry.key = NULL;
		return (0);
	}
	return (1);
}

char *ft_search_dict(t_node *dict, char *key)
{
	t_node *curr_node;

	curr_node = dict;
	while (curr_node != NULL) {
		if (equals(curr_node->dict_entry.key, key) == 0)
			return (curr_node->dict_entry.value);
		curr_node = curr_node->next;
	}
	return (NULL);
}

int parse_dictionary(int fd, t_node **head_dict)
{
	t_node *curr_node;
	t_node *new_node;
	char buffer[4096];

	*head_dict = NULL;
	curr_node = NULL;
	while (read_line(fd, buffer, sizeof(buffer)) > 0) {
		if (buffer[0] == '\0')
			continue;
		new_node = malloc(sizeof(*new_node));
		if (!new_node)
			return (0);
		if (!parse_line(buffer, new_node)) {
			free(new_node);
			return (0);
		}
		new_node->next = NULL;
		if (!*head_dict)
			*head_dict = new_node;
		else
			curr_node->next = new_node;
		curr_node = new_node;
	}
	return (1);
}
