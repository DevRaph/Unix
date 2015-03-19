/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 18:55:52 by rpinet            #+#    #+#             */
/*   Updated: 2014/11/10 19:09:28 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*ptr;
	int		max;

	max = (int)len + (int)start;
	if (max > (int)ft_strlen(s) || !s || !(str = ft_strnew(len)))
		return (NULL);
	ptr = str;
	s += start;
	while (len--)
		*str++ = *s++;
	return (ptr);
}
