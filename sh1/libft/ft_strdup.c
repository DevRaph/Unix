/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 18:01:14 by rpinet            #+#    #+#             */
/*   Updated: 2014/12/29 20:47:34 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
/*
void	ft_bcopy(char *src, char *dst, unsigned int len)
{
	if (src < dst)
	{
		src += len;
		dst += len;
		while (len--)
			*--dst = *--src;
	}
	else if (src != dst)
		while (len--)
			*dst++ = *src++;
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*copy;

	len = ft_strlen(s) + 1;
	if (!(copy = (char *)ft_memalloc((unsigned int)len)))
		return (NULL);
	ft_bcopy((char *)s, copy, len);
	return (copy);
}
*/
char		*ft_strdup(const char *s)
{
	char	*copy;
	char	*ptr;
	int		size;

	ptr = (char *)s;
	size = 0;
	copy = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	while (ptr[size])
	{
		copy[size] = ptr[size];
		size++;
	}
	copy[size] = '\0';
	//free(copy);
	return (copy);
}

