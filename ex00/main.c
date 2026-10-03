#include "rush02.h"

int	main(int argc, char **argv)
{
	if (argc >= 4 || argc <= 1)
	{
		ft_putstr("Error\n");
		return (1);
	}
    if (argc == 2)
        ft_convert_number_rosetta(FILENAME_DICT, argv[1]);
    else
        ft_convert_number_rosetta(argv[1], argv[2]);
	return (0);
}
