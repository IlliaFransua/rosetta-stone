#include "rush02.h"

int main(int argc, char **argv)
{
	if (!(argc == 2 || argc == 3)) {
		print("Error\n");
		return (1);
	}
	if (argc == 2)
		convert_number(FILENAME_DICT, argv[1]);
	else
		convert_number(argv[1], argv[2]);
	return (0);
}
