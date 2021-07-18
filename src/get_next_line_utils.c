#include "get_next_line.h"

char *ft_strchr(const char *s, int c) {
  size_t count;

  count = 0;
  while (s[count] && ((unsigned char *) s)[count] != (unsigned char) c)
	count++;
  if (s[count] || (unsigned char) c == '\0')
	return ((char *) s + count);
  else
	return (NULL);
}

char *ft_strjoin(char const *s1, char const *s2) {
  size_t i;
  size_t k;
  char *new;

  if (!s1 && !s2)
	return (NULL);
  new = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
  if (new) {
	i = 0;
	k = 0;
	while (s1 && s1[i] && s1[i] != '\n') {
	  new[i] = s1[i];
	  i++;
	}
	while (s2 && *s2 != '\0' && *s2 != '\n')
	  new[i + k++] = *s2++;
	new[i + k] = '\0';
	free((char *) s1);
	return (new);
  }
  return (NULL);
}

char *ft_strdup(const char *s) {
  size_t i;
  size_t len;
  char *dup;

  i = 0;
  len = ft_strlen(s);
  if ((dup = (char *) malloc(sizeof(char) * len + 1))) {
	while (i < len)
	  dup[i++] = *s++;
	dup[i] = '\0';
	return (dup);
  }
  return (NULL);
}

size_t ft_strlen(const char *s) {
  size_t count;

  count = 0;
  if (s)
	while (*s++)
	  count++;
  return (count);
}
