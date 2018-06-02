/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 22:41:03 by astrole           #+#    #+#             */
/*   Updated: 2018/04/02 22:43:08 by astrole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

static t_file	*set_file_struct(t_file *file)
{
	file->buf = 0;
	file->len = 0;
	file->count = 0;
	file->nread = 0;
	return (file);
}

char			*ft_open(char *name)
{
	t_file file;

	file.fd = open(name, O_RDONLY);
	file = *set_file_struct(&file);
	while (1)
	{
		ft_bzero(file.tmp, 1024);
		file.nread = read(file.fd, file.tmp, (BLOCK_SIZE) * sizeof(char));
		if (file.nread <= 0)
			break ;
		if (file.buf)
			file.buf = ft_realloc(file.buf,
((file.len + file.nread) + 1) * sizeof(char), (file.len + 1) * sizeof(char));
		else
			file.buf = ft_memalloc((file.nread + 1) * sizeof(char));
		file.len += file.nread;
		if (!file.buf)
			return (NULL);
		file.buf = ft_strcat(file.buf, file.tmp);
	}
	close(file.fd);
	if (file.buf == NULL)
		return (NULL);
	file.buf[file.len] = '\0';
	return (file.buf);
}
