/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_right.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 16:07:04 by rpinet            #+#    #+#             */
/*   Updated: 2014/11/26 16:42:43 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim_right(char const *s, size_t n)
{
	char *str;

	if (!s || !*s)
		return ((char *)s);
	if (n > ft_strlen(s))
		return ("");
	str = ft_strndup(s, (size_t)(ft_strlen(s) - n));
	//free(str);
	return (str);
}
