/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 18:01:14 by rpinet            #+#    #+#             */
/*   Updated: 2014/11/26 15:01:47 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strndup(char const *s, size_t n)
{
	char	*copy;
	char	*ptr;
	size_t	size;

	if (!s)
		return (NULL);
	ptr = (char *)s;
	size = 0;
	copy = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	while (s && *s && size < n)
	{
		copy[size] = ptr[size];
		size++;
	}
	copy[size] = '\0';
	return (copy);
}
