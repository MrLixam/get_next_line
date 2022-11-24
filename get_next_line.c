#include "get_next_line.h"

char *ft_read_a_line(static char *save, int fd)
{
	char	*tmp;
    int		b_read;

	b_read = 1;
	tmp = malloc(BUFFER_SIZE + 1)
	while (!ft_strchr(save, '\n') && b_read != 0)
	{
		b_read = read(fd, tmp, BUFFER_SIZE);
		if (b_read == -1)
			return (NULL);
		tmp[b_read] == '\0';
		save = ft_strjoin(save, tmp);
	}
	return (save);
}

char *get_curr_line(char *save, )
{
	int i;
	char *rv;

	i = 0;
	while(save[i] && save[i] != '\n')
		i++;
	rv = malloc(i + 2);
	if (!rv)
		return (NULL);
	i = 0;
	while(save[i] && save[i] != '\n')
	{
		rv[i] = save[i];
		i++;
	}
	if (*save == '\n')
	{
		rv[i] = save[i];
		i++
	}
	rv[i] = '\0';
	return (rv)
}

char *get_next_line(int fd)
{
	static char	*save;
    char		*buffer;

	if (fd < 0 || fd > 1023)
		return(NULL)
}
