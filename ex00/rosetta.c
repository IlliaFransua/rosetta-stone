#include "rush02.h"

// static void	ft_get_args(int argc, char **argv, char **num, char **filename)
// {
// 	if (argc == 3)
// 	{
// 		*filename = argv[1];
// 		*num = argv[2];
// 	}
// 	else
// 	{
// 		*filename = FILENAME_DICT;
// 		*num = argv[1];
// 	}
// 	return ;
// }

// static char	*ft_validate_number(char *num)
// {

static void	ft_cleanup(int fd, t_node *dictionary)
{
	t_node	*curr_node;
	t_node	*node_to_clean;

	// ALSO CLEAN NUM AND EVERYTHING ELSE UP TO THE END

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

// }

void	ft_convert_number_rosetta(char *filename, char *num)
{
    char    *clean_num;
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
	dictionary = ft_parse_dictionary(fd);
	if (dictionary)
		ft_convert_number(clean_num, dictionary);
	else
		ft_putstr("Dict Error\n"); // AND CLEAN RESOURCES
	ft_cleanup(fd, dictionary);
	return ;
}