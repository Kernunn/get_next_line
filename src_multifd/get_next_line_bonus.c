#include "get_next_line_bonus.h"

int		get_next_line(int fd, char **line)
{
	static	t_fd	fd_tab[1027];
	t_list			*begin_line;

	begin_line = NULL;
	if (!line || fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	while ((fd_tab[fd].i == -1 && fd) ||
			(fd_tab[fd].count_read = read(fd, fd_tab[fd].buf, BUFFER_SIZE)))
	{
		if (fd_tab[fd].count_read == -1)
			return (-1);
		if (!(fd_tab[fd].j = ft_read_next(&(fd_tab[fd]), &begin_line)) ||
				fd_tab[fd].j == -1)
			break ;
	}
	if (fd_tab[fd].j == -1)
		return (-1);
	if (!ft_get_line(begin_line, line))
		return (-1);
	ft_lstclear(&begin_line);
	if (fd_tab[fd].count_read && !fd)
		return (1);
	if (fd_tab[fd].i == -2 || fd_tab[fd].count_read == 0)
		return (0);
	return (1);
}

int		ft_read_next(t_fd *f, t_list **begin_line)
{
	while (f->count_add < f->count_read && *(f->buf + f->count_add) != '\n')
		f->count_add = f->count_add + 1;
	if (!ft_lstadd_back(begin_line, f->buf, f->count_add))
		return (-1);
	if (f->count_add == f->count_read)
	{
		f->i = (f->count_read == BUFFER_SIZE) ? 0 : -2;
		f->count_add = 0;
		return ((f->count_read == BUFFER_SIZE) ? 1 : 0);
	}
	f->count_add = f->count_add + 1;
	f->i = -1;
	if (f->count_add == f->count_read)
	{
		f->i = 0;
		f->count_add = 0;
	}
	return (0);
}

int		ft_get_line(t_list *begin_line, char **line)
{
	t_list	*tmp;
	int		count;

	count = 0;
	tmp = begin_line;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	tmp = begin_line;
	*line = (char *)ft_calloc(count * BUFFER_SIZE + 1, sizeof(char));
	if (!*line)
		return (0);
	while (tmp)
	{
		ft_strlcat(*line, tmp->line, count * BUFFER_SIZE + 1);
		tmp = tmp->next;
	}
	return (1);
}
