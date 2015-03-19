/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:24:27 by rpinet            #+#    #+#             */
/*   Updated: 2014/11/06 15:11:50 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*copy;

	ptr = (unsigned char *)src;
	copy = (unsigned char *)dest;
	while (n--)
	{
		*copy = *ptr;
		if (*ptr == (unsigned char)c)
			return (copy + 1);
		copy++;
		ptr++;
	}
	return (NULL);
}
