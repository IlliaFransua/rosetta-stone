#include "rush02.h"

void ft_putstr(char *str) {
  while (*str != '\0') {
    write(1, str, 1);
    str++;
  }
}

int ft_strlen(char *str) {
  int index;

  index = 0;
  while (str[index] != '\0') {
    index++;
  }
  return (index);
}

int ft_is_numeric(char c) { return (c >= '0' && c <= '9'); }

char *ft_strdup(char *src) {
  int i;
  char *dup;

  dup = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
  if (!dup)
    return (NULL);
  i = 0;
  while (src[i] != '\0') {
    dup[i] = src[i];
    i++;
  }
  dup[i] = '\0';
  return (dup);
}

char *ft_strndup(char *src, int n) {
  int i;
  int len;
  char *dup;

  len = ft_strlen(src);
  if (n > len)
    n = len;
  dup = (char *)malloc((n + 1) * sizeof(char));
  if (!dup)
    return (NULL);
  i = 0;
  while (i < n) {
    dup[i] = src[i];
    i++;
  }
  dup[i] = '\0';
  return (dup);
}
