#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	int			count_read;
	static char	*remainder;
	char		*n_here;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || !(*line = ft_strdup("")))
		return (-1);
	count_read = 0;
	if (ft_remainder(line, &remainder, &n_here))
		return (-1);
	while (!n_here && (count_read = read(fd, buf, BUFFER_SIZE)))
	{
		if (count_read == -1)
			return (-1);
		buf[count_read] = '\0';
		if ((n_here = ft_strchr(buf, '\n')))
		{
			remainder = ft_strdup(n_here + 1);
			*line = ft_strjoin(*line, buf);
			return ((*line && remainder) ? 1 : -1);
		}
		else if (!(*line = ft_strjoin(*line, buf)))
			return (-1);
	}
	return ((n_here || count_read) ? 1 : 0);
}

int	ft_remainder(char **line, char **remainder, char **n_here)
{
	char	*tmp;

	*n_here = NULL;
	if (*remainder)
	{
		tmp = *remainder;
		*n_here = ft_strchr(*remainder, '\n');
		if (!(*line = ft_strjoin(*line, *remainder)))
			return (1);
		if (*n_here)
		{
			if (!(*remainder = ft_strdup(*n_here + 1)))
				return (1);
			free(tmp);
		}
		else
		{
			free(*remainder);
			*remainder = NULL;
		}
	}
	return (0);
}
