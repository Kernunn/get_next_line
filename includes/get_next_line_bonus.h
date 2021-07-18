#	ifndef GET_NEXT_LINE_BONUS_H
#	define GET_NEXT_LINE_BONUS_H

#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct s_fd {
  char buf[BUFFER_SIZE + 1];
  int count_read;
  int count_add;
  int i;
  int j;
} t_fd;

typedef struct s_list {
  char *line;
  struct s_list *next;
} t_list;

int get_next_line(int fd, char **line);
int ft_read_next(t_fd *f, t_list **begin_list);
int ft_lstadd_back(t_list **begin_list, char *line, int count);
int ft_get_line(t_list *begin_list, char **line);
char *ft_substr(char const *s, unsigned int start, size_t len);
size_t ft_strlcat(char *dest, const char *src, size_t size);
void ft_lstclear(t_list **begin_line);
void *ft_calloc(size_t nmemb, size_t size);

#	endif
