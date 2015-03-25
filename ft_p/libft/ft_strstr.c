/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 20:14:00 by rpinet            #+#    #+#             */
/*   Updated: 2014/11/07 16:03:16 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	char			*str;
	unsigned int	len;

	if (*s2 == '\0')
		return ((char *)s1);
	str = (char *)s1;
	len = ft_strlen(s2);
	while (*str)
	{
		if (*str == *s2)
		{
			if (ft_strncmp((const char *)str, s2, len) == 0)
				return (str);
		}
		str++;
	}
	return (NULL);
}
