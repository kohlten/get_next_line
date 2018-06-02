/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 21:24:02 by astrole           #+#    #+#             */
/*   Updated: 2018/04/24 21:24:04 by astrole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int		can_find_next_line(char *cache)
{
	char	*s;

	s = cache;
	if (!s)
		return (0);
	while (*s)
		if (*s++ == '\n')
			return (1);
	if (!*s)
		return (0);
	return (0);
}

static char		*split(t_cache *cache)
{
	int		i;
	char	*out;
	char	*new;
	char	*tmp;

	out = ft_strnew(ft_strlen(cache->cache));
	if (!out)
		return (NULL);
	i = -1;
	while (cache->cache[++i] != '\n' && cache->cache[i])
		out[i] = cache->cache[i];
	tmp = cache->cache;
	tmp += i + 1;
	printf("I: %s\n", tmp);
	new = ft_strnew(ft_strlen(tmp));
	if (!new)
		return (NULL);
	new = ft_strcpy(new, tmp);
	free(cache->cache);
	cache->cache = ft_strnew(ft_strlen(new));
	if (!cache->cache)
		return (NULL);
	cache->cache = ft_strcpy(cache->cache, new);
	cache->len = ft_strlen(cache->cache);
	free(new);
	return (out);
}

int				add_to_cache(int fd, t_cache *cache)
{
	char	tmp[BUFF_SIZE + 1];
	int		nread;

	nread = 0;
	ft_bzero(tmp, BUFF_SIZE + 1);
	nread = read(fd, tmp, BUFF_SIZE);
	if (nread <= 0)
		return (nread);
	cache->cache = ft_realloc(cache->cache,
	(cache->len + nread) + 1 * sizeof(char), (cache->len + 1) * sizeof(char));
	if (!cache->cache)
		return (-1);
	cache->len += nread;
	ft_strcat(cache->cache, tmp);
	return (nread);
}

int				get_next_line(const int fd, char **line)
{
	static t_cache	cache = {0, 0};
	int				out;

	if (fd < 0 || line == NULL || read(fd, 0, 0) < 0 || BUFF_SIZE <= 0)
		return (-1);
	while (!(can_find_next_line(cache.cache)))
	{
		out = add_to_cache(fd, &cache);
		if (out == 0)
			break ;
		else if (out <= -1)
			return (-1);
	}
	*line = split(&cache);
	printf("Len: %d out: %d %s\n", cache.len, out, cache.cache);
	if (cache.len == 0 && out == 0)
	{
		printf("return 0\n");
		return ((int)(cache.cache = 0));
	}
	printf("return 1\n");
	return (1);
}
