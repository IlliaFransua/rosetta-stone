#include "rush02.h"

#include <stdio.h>

static int	ft_read_line(int fd, char *buffer)
{
	int i;
	int	t;
	char	c;

	i = 0;
	t = read(fd, &c, 1);
	while (t > 0 && c != '\n')
	{
		buffer[i] = c;
		i++;
		t = read(fd, &c, 1);
	}
	buffer[i] = '\0';
	if (t < 0)
		return (-1);
	if (t == 0 && i == 0)
		return (0);
	return (1);
}

// static void	ft_append_node(t_node *new_node, t_node **curr_node)
// {
// 	new_node->next = NULL;
// 	if (curr_node)
// 		curr_node->next = new_node;
// 	curr_node = new_node;
// }

static int	ft_get_last_val_char(char *buffer)
{
	int	i;

	i = 0;
	while(buffer[i] >= ' ' && buffer[i] <= '~')
		i++;
	if (buffer[i] != '\0')
		return (0);
	while(i > 0 && buffer[i - 1] == ' ')
		i--;
	return (i);
}

static int ft_parse_line(char *buffer, t_node *new_node)
{
	int i;
	int key_len;
	int start_val;
	int	val_len;

	i = 0;
	while (ft_is_numeric(buffer[i]))
		i++;
	key_len = i;				
	while (buffer[i] == ' ')
		i++;
	if (key_len == 0 || buffer [i++] != ':')
		return (0);				// ERROR PARSING DICT
	while (buffer[i] == ' ')
		i++;
	start_val = i;
	val_len = ft_get_last_val_char(&buffer[start_val]);
	if (val_len == 0)
		return (0);
	new_node->dict_entry.key = ft_strndup(buffer, key_len);
	new_node->dict_entry.value = ft_strndup(&buffer[start_val], val_len);
	if(!new_node->dict_entry.key || !new_node->dict_entry.value)
		return (0);
	return (1);
}

void	print_struct(t_node *dict)
{
	t_node	*curr_node;

	curr_node = dict;
	while (curr_node != NULL)
	{
		printf("%s\n", curr_node->dict_entry.key);
		printf("%s\n", curr_node->dict_entry.value);
		curr_node = curr_node->next;
	}
}

int	ft_parse_dictionary(int fd, t_node **head_dict)
{
	t_node	*curr_node;
	t_node	*new_node;
	char	buffer[4096];

	*head_dict = NULL;
	curr_node = NULL;
	while (ft_read_line(fd, buffer) > 0)
	{
		if (buffer[0] == '\0')
			continue ;
		new_node = (t_node *) malloc(sizeof(t_node));
		if (!new_node)
			return (0);
		if (!ft_parse_line(buffer, new_node))
		{
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
	print_struct(*head_dict);			// DELETE
	return (1);
}




	/*
	t_node	*ft_parse_dictionary(int fd)
{	// WHERE DO I CLEAN RESOURCES??
	char	c;
	t_node	*head_dict;
	t_node	*curr_node;
	t_node	*new_node;
	char	buffer[4096];

	head_dict = NULL;
	curr_node = NULL;
	while (ft_read_line(fd, buffer) > 0)
	{
		if (buffer[0] == '\0')
			continue ;
		new_node = (t_node *) malloc(sizeof(t_node));
		

	}
	
	
	head_dict = (t_node *) malloc(sizeof(t_node));
	if (!head_dict)
		return (NULL);			// CHECK
	curr_node = head_dict;
	while (ft_read_line(fd, buffer) > 0)
	{
		if (buffer[0] == '\0')
			continue ;
		new_node = (t_node *) malloc(sizeof(t_node));
		if (!new_node)
			return (NULL);
		if (!ft_parse_line(buffer, new_node, curr_node))
			return (NULL);
		printf("%s\n", buffer);
	}
	return (head_dict);
	*/