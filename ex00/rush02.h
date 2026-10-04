#ifndef RUSH02_H
#	define RUSH02_H

#	if defined(_WIN32) || defined(_WIN64)
#		include <io.h>
#	elif defined(__APPLE__) || defined(__linux__)
#		include <unistd.h>
#	else
#		error
#	endif

#include <fcntl.h>
#include <stdlib.h>

# define FILENAME_DICT "numbers.dict"
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

typedef struct s_word_node
{
    char	*str;
	struct s_word_node	*next;
}   t_word_node;

void	ft_putstr(char *str);
int	ft_strlen(char *str);
int	ft_is_numeric(char c);
void	ft_convert_number_rosetta(char *filename, char *num);
int	ft_strcmp(char *s1, char *s2);
char	*ft_strndup(char *src, int n);
int	ft_parse_dictionary(int fd, t_node **head_dict);
char	*ft_search_dict(t_node *dict, char *key);
int	ft_push_front(t_word_node **words_head, char *str);
void	ft_print_words(t_word_node *words_head);
int	ft_get_hundreds(t_node *dictionary, t_word_node **words_head
	, char digit);
int	ft_get_units(t_node *dict, t_word_node **words_head, char *num, int pos);
int	ft_get_ten_power(t_node *dict, t_word_node **words_head, char *num, int pos);


#endif