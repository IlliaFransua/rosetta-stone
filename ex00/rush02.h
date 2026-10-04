#ifndef RUSH02_H
#define RUSH02_H

#if defined(_WIN32) || defined(_WIN64)
#include <io.h>
#elif defined(__APPLE__) || defined(__linux__)
#include <unistd.h>
#else
#error
#endif

#include <fcntl.h>
#include <stdlib.h>

#define FILENAME_DICT "numbers.dict"
typedef struct s_dict {
  char *key;
  char *value;
} t_dict;

typedef struct s_node {
  t_dict dict_entry;
  struct s_node *next;
} t_node;

void ft_putstr(char *str);
int ft_strlen(char *str);
void ft_convert_number_rosetta(char *filename, char *num);
char *ft_strdup(char *src);
char *ft_strndup(char *src, int n);
t_node *ft_parse_dictionary(int fd);

#endif
