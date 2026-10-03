#ifndef RUSH02_H
# define RUSH02_H
# include <io.h>
# include <fcntl.h>

# define FILENAME_DICT "numbers.dict"
void	ft_putstr(char *str);
int	ft_strlen(char *str);
void	ft_convert_number_rosetta(char *filename, char *num);


typedef struct s_dict
{
    char    *key;
    char    *value;
}   t_dict;

typedef struct s_node
{
    t_dict  dict_entry;
    struct s_node  *next;
}   t_node;

#endif