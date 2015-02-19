/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 19:23:52 by rpinet            #+#    #+#             */
/*   Updated: 2014/12/29 21:04:27 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_count_word(char const *s, char c)
{
	int		count;
	int		valid;

	valid = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && valid == 0)
		{
			count++;
			valid = 1;
		}
		if (*s == c && valid == 1)
			valid = 0;
		s++;
	}
	return (count);
}

size_t	ft_size_word(char const *s, char c)
{
	int		size;

	size = 0;
	while (*s != c && *s != '\0')
	{
		s++;
		size++;
	}
	return (size);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;

	if (!s)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(*tab) * (ft_count_word(s, c) + 1))))
		return (NULL);
	i = 0;
	while (s && *s)
	{
		if (*s != c)
		{
			tab[i] = ft_strndup(s, ft_size_word(s, c));
			s += ft_size_word(s, c);
			i++;
		}
		else
			s++;
	}
	tab[i] = '\0';
	//free(tab);
	return (tab);
}
