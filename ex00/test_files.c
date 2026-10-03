// #include <io.h>
// #include <fcntl.h>

// int main(void)
// {
// 	const char	*filename = "numbers.dict";
// 	int		fd;
// 	char	buffer[4096];
// 	int		t;
// 	int		i;

// 	fd = open(filename, O_RDONLY);
// 	if (fd < 0)
// 	{
// 		write(2, "Error opening file \n", 19);
// 		return (1);
// 	}

// 	i = 0;
// 	while ((t = read(fd, buffer, 4096)) > 0)
// 	{
// 		while(i < t)
// 		{
// 			write(1, &buffer[i], 1);
// 			i++;
// 		}
// 	}

// 	close (fd);

// }