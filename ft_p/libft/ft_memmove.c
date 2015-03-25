/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 11:57:58 by rpinet            #+#    #+#             */
/*   Updated: 2014/11/10 14:54:35 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char *ptr_s;
	unsigned char *ptr_d;

	ptr_s = (unsigned char *)src;
	if (dst <= src)
		return (ft_memcpy(dst, (void *)src, n));
	ptr_s = (unsigned char *)src + n;
	ptr_d = dst + n;
	while (n--)
		*--ptr_d = *--ptr_s;
	return ((void *)ptr_d);
}
