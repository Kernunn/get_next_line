#	ifndef GET_NEXT_LINE_H
#	define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

int get_next_line(int fd, char **line);
int ft_remainder(char **line, char **remainder, char **n_here);
char *ft_strchr(const char *s, int c);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strdup(const char *s);
size_t ft_strlen(const char *s);

#	endif
