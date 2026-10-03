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

static char	*ft_validate_number(char *num)
{


}

void	ft_convert_number_rosetta(char *filename, char *num)
{
    char    *clean_num;
	int	fd;
	t_node	*dictionary;

	fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
		ft_putstr("Dict Error\n");
		return ;
    }
	clean_num = ft_validate_number(num);
    if (!clean_num)
    {
		ft_putstr("Error\n");
		return ;
    }
	dictionary = ft_parse_dictionary(fd);
	if (!dictionary)
	{
		ft_putstr("Dict Error\n");
		return ;
	}
	ft_print_number(clean_num, dictionary);
	return ;
}