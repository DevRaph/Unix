/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnsplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 17:02:48 by rpinet            #+#    #+#             */
/*   Updated: 2014/11/26 17:12:03 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_count_word(char const *s, char const *c)
{
	int		count;
	int		valid;
	int		tmp;

	valid = 0;
	count = 0;
	while (*s)
	{
		tmp = ft_strncmp(s, c, (size_t)ft_strlen(c));
		if (tmp != 0 && valid == 0)
		{
			count++;
			valid = 1;
		}
		if (tmp == 0 && valid == 1)
			valid = 0;
		s++;
	}
	return (count);
}

size_t	ft_size_word(char const *s, char c)
{
	size_t		size;

	size = 0;
	while (*s != c && *s != '\0')
	{
		s++;
		size++;
	}
	return (size);
}

char	**ft_strsnplit(char const *s, char *pat)
{
	char	**tab;
	int		i;

	if (!s)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(*tab) * (ft_count_word(s, pat) + 1))))
		return (NULL);
	i = 0;
	while (s && *s)
	{
		if (ft_strncmp(s, pat, (size_t)ft_strlen(pat)) != 0)
		{
			tab[i] = ft_strndup(s, ft_size_word(s, pat));
			s += ft_size_word(s, pat);
			i++;
		}
		else
			s += ft_strlen(pat);
	}
	tab[i] = '\0';
	return (tab);
}
