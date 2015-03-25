/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 17:13:19 by rpinet            #+#    #+#             */
/*   Updated: 2014/11/26 17:14:20 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_size_word(char const *s, char *c)
{
	int		size;

	if (!s || !*s || !c)
		return (0);
	size = 0;
	while (ft_strncmp(s, c, (size_t)ft_strlen(c)) != 0 && *s != '\0')
	{
		s++;
		size++;
	}
	return (size);
}
