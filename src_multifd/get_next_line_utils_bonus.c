#include "get_next_line_bonus.h"

int ft_lstadd_back(t_list **begin_line, char *line, int count) {
  t_list *new;
  t_list *tmp;
  int start;

  start = count;
  new = (t_list *) malloc(sizeof(t_list));
  if (!new)
	return (0);
  while (start > 0 && line[start - 1] != '\n')
	start--;
  if (!(new->line = ft_substr(line, start, count - start)))
	return (0);
  new->next = NULL;
  tmp = *begin_line;
  if (*begin_line) {
	while (tmp->next)
	  tmp = tmp->next;
	tmp->next = new;
  } else
	*begin_line = new;
  return (1);
}

char *ft_substr(char const *s, unsigned int start, size_t len) {
  size_t i;
  size_t len_s;
  char *sub;

  if (!s)
	return (NULL);
  i = 0;
  len_s = 0;
  while (s[len_s])
	len_s++;
  sub = (char *) malloc(sizeof(char) * (len + 1));
  if (sub) {
	while (i < len && s[i + start]) {
	  sub[i] = s[i + start];
	  i++;
	}
	sub[i] = '\0';
	return (sub);
  }
  return (NULL);
}

size_t ft_strlcat(char *dest, const char *src, size_t size) {
  size_t i;

  i = 0;
  while (dest[i] && i < size)
	i++;
  if (size != 0 && i != size) {
	while (i < size - 1 && *src)
	  dest[i++] = *src++;
	dest[i] = '\0';
  }
  while (*src++)
	i++;
  return (i);
}

void ft_lstclear(t_list **lst) {
  t_list *tmp;

  if (lst)
	while (*lst) {
	  tmp = (*lst)->next;
	  free((*lst)->line);
	  free(*lst);
	  *lst = tmp;
	}
}

void *ft_calloc(size_t nmemb, size_t size) {
  void *ans;
  size_t k;

  k = 0;
  if (size && nmemb > SIZE_MAX / size)
	return (NULL);
  ans = malloc(size * nmemb);
  if (ans) {
	while (k < size * nmemb)
	  ((unsigned char *) ans)[k++] = '\0';
	return (ans);
  }
  return (NULL);
}
