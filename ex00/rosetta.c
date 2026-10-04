#include "rush02.h"

#include <stdio.h>

static void ft_cleanup(int fd, t_node *dictionary) {
  t_node *curr_node;
  t_node *node_to_clean;

  // ALSO CLEAN NUM AND EVERYTHING ELSE UP TO THE END

  curr_node = dictionary;
  while (curr_node != NULL) {
    node_to_clean = curr_node;
    curr_node = curr_node->next;
    free(node_to_clean->dict_entry.key);
    free(node_to_clean->dict_entry.value);
    free(node_to_clean);
  }
  close(fd);
  return;
}

void ft_convert_number_rosetta(char *filename, char *num) {
  char *clean_num;
  int fd;
  t_node *dictionary;

  clean_num = clean_number(num);
  if (!clean_num) {
    ft_putstr("Error\n");
    return;
  }
  fd = open(filename, O_RDONLY);
  if (fd < 0) {
    ft_putstr("Dict Error\n");
    return;
  }
  if (ft_parse_dictionary(fd, &dictionary))
    ft_putstr("OK");
  else
    ft_putstr("Dict Error\n"); // AND CLEAN RESOURCES
  printf("%s\n", num);
  ft_cleanup(fd, dictionary);
  return;
}
