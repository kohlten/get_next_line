/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 21:22:00 by astrole           #+#    #+#             */
/*   Updated: 2018/04/24 21:22:03 by astrole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# include <unistd.h>
# include "libft.h"

typedef	struct	s_cache
{
	char	*cache;
	int		len;
}				t_cache;

int				get_next_line(const int fd, char **line);

#endif
