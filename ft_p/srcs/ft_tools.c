/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 17:06:47 by rpinet            #+#    #+#             */
/*   Updated: 2015/03/30 17:06:50 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_p.h"
#include <stdlib.h>

void				ft_print_cmd(char **cmd)
{
	int				i;

	i = 0;
	while (cmd && cmd[++i])
	{
		ft_putstr(cmd[i]);
		ft_putstr(" "); // attention dernier
	}
	ft_putstr("\n");
}

char				*ft_clean(char *s)
{
	char			*str;
	char			*ptr;

	if (!(str = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	ptr = str;
	while (s && *s)
	{
		if (ft_isspace(*s))
		{
			if (s + 1 && *(s + 1) && !ft_isspace(*(s + 1)))
				*ptr++ = ' ';
		}
		else
			*ptr++ = *s;
		s++;
	}
	str = ft_strtrim(str);
	// fuite memoiiiiiiiiiiiiiire
	return (str);
}