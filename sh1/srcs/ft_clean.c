/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 18:41:49 by rpinet            #+#    #+#             */
/*   Updated: 2015/02/17 20:16:48 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell1.h"
#include "../libft/libft.h"
#include <stdlib.h>

/*
char		*ft_clean_path(char *s)
{

	return ()
}*/

char		*ft_clean(char *s)
{
	char	*str;
	char	*ptr;

	if (!(str = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	ptr = str;
	while (s && *s)
	{
		if (ft_isspace(*s))
		{
			if (s + 1 && *(s + 1) && !ft_isspace(*(s + 1)))
				*ptr++ = *s;
		}
		else
			*ptr++ = *s;
		s++;
	}
	str = ft_strtrim(str);
	return (str);
}
