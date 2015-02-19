/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 16:18:31 by rpinet            #+#    #+#             */
/*   Updated: 2014/12/29 20:52:44 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_suite(int ret, char **stat, char **line)
{
	if (ret == -1)
		return (-1);
	if (*stat == NULL || **stat == '\0')
		return (0);
	*line = *stat;
	*stat = NULL;
	return (1);
}

int		get_next_line(int const fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	char		*ptr;
	static char	*stat;
	int			ret;

	if (!line || fd < 0)
		return (-1);
	while (!ft_strchr(stat, '\n'))
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) <= 0)
			break ;
		buf[ret] = '\0';
		stat = (stat == 0) ? ft_strdup(buf) : ft_strjoin(stat, buf);
	}
	if ((ptr = ft_strchr(stat, '\n')))
	{
		*line = stat;
		stat = ptr + 1;
		*ptr = '\0';
		return (1);
	}
	else
		return (ft_suite(ret, &stat, line));
	return (ret);
}
