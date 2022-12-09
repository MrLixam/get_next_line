/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:28:54 by lvincent          #+#    #+#             */
/*   Updated: 2022/12/05 20:20:12 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

char	*ft_strchr(char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*rv;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0'
	}
	if (!s1 || !s2)
		return(NULL);
	rv = (char *)malloc(1 + ft_strlen(s1) + ft_strlen(s2));
	if (!rv)
		return (NULL);
	ft_memcpy(rv, s1, ft_strlen(s1));
	ft_memcpy(rv + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	free(s1);
	return (rv);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*rv;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		rv = malloc(1);
		rv[0] = '\0';
		return (rv);
	}
	if (ft_strlen(s) >= (start + len))
		rv = malloc(len + 1);
	else
		rv = malloc(1 + len - ((start + len) - ft_strlen(s)));
	if (!rv)
		return (NULL);
	i = 0;
	while ((i < len) && s[start + i])
	{
		rv[i] = s[start + i];
		i++;
	}
	rv[i] = '\0';
	return (rv);
}
