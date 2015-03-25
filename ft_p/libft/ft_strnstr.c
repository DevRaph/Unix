/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 12:23:32 by rpinet            #+#    #+#             */
/*   Updated: 2014/11/07 13:48:45 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char			*str;
	unsigned int	len;

	if (*s2 == '\0')
		return ((char *)s1);
	str = (char *)s1;
	len = n - ft_strlen(s2) + 1;
	while (*str && len--)
	{
		if (*str == *s2)
		{
			if (ft_strncmp((const char *)str, s2, ft_strlen(s2)) == 0)
				return (str);
		}
		str++;
	}
	return (NULL);
}
