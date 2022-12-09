/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:28:57 by lvincent          #+#    #+#             */
/*   Updated: 2022/12/05 20:22:49 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

static char	*read_mini_line(char *save, int fd)
{
	char	*tmp;
	int		b_read;

	b_read = 1;
	tmp = malloc(BUFFER_SIZE + 1);
	while (!ft_strchr(save, '\n') && b_read != 0)
	{
		b_read = read(fd, tmp, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[b_read] = '\0';
		save = ft_strjoin(save, tmp);
	}
	free(tmp);
	return (save);
}

static char *get_curr_line(char *save)
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
	if (save[i] == '\n')
	{
		rv[i] = save[i];
		i++;
	}
	rv[i] = '\0';
	return (rv);
}


static char *new_save(char *save)
{
	char *rv;
	int i;
	int j;

	i = 0;
	while(save[i] && save[i] != '\n')
		i++;
	rv = malloc(ft_strlen(save) - i + 1);
	if (!rv)
		return(NULL);
	i++;
	j = 0;
	while(save[i])
		rv[j++] = save[i++];
	rv[j] = '\0';
	free(save);
	return (rv);	
}

char *get_next_line(int fd)
{
	static char	*save = NULL;
    char		*buffer;

	if (fd < 0 || fd > 1023)
		return(NULL);
	save = read_mini_line(save, fd);
	if (!save)
		return (NULL);
	buffer = get_curr_line(save);
	save = new_save(save);
	return (buffer);
}

int main()
{
	int fd = open("amogus.txt", O_RDONLY);
	char *line;
	int i = 0;
	while (i <= 4)
	{
		line = get_next_line(fd);
		printf("%d : %s", i, line);
		free(line);
		i++;
	}
	return (0);
}