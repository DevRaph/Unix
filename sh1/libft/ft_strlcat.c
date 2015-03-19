/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 14:09:14 by rpinet            #+#    #+#             */
/*   Updated: 2014/11/13 17:30:53 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = ft_strlen((const char *)dst) + ft_strlen(src);
	j = 0;
	k = 0;
	while (dst[j])
		j++;
	while (src[k] && j < size - 1)
		dst[j++] = src[k++];
	dst[j] = 0;
	if (size + ft_strlen(src) < i)
		return (size + ft_strlen(src));
	return (i);
}
