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

	i = -1;
	out = ft_strnew(ft_strlen(cache->cache));
	if (!out)
		return (NULL);
	while (cache->cache[++i] != '\n' && cache->cache[i])
		out[i] = cache->cache[i];
	tmp = cache->cache;
	tmp += i + 1;
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

int				get_next_line(const int fd, char **line)
{
	char			tmp[BUFF_SIZE + 1];
	static t_cache	cache = {0, 0};
	int				nread;

	if (fd < 0 || line == NULL || read(fd, tmp, 0) < 0 || BUFF_SIZE <= 0)
		return (-1);
	nread = 0;
	while (!(can_find_next_line(cache.cache)))
	{
		ft_bzero(tmp, BUFF_SIZE + 1);
		nread = read(fd, tmp, BUFF_SIZE);
		if (nread == 0)
			break ;
		cache.cache = ft_realloc(cache.cache,
		(cache.len + nread) + 1 * sizeof(char), (cache.len + 1) * sizeof(char));
		if (!cache.cache)
			return (-1);
		cache.len += nread;
		ft_strcat(cache.cache, tmp);
	}
	*line = split(&cache);
	if (!**line && nread == 0)
		return ((int)(cache.cache = 0));
	return (1);
}
