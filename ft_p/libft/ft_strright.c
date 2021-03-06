/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strright.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 15:42:47 by rpinet            #+#    #+#             */
/*   Updated: 2014/11/26 15:58:30 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strright(char const *s, size_t n)
{
	if (s && *s && n <= ft_strlen(s))
		return ((char *)s + ft_strlen(s) - n);
	return ((char *)s);
}
