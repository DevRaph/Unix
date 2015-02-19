/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_left.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 16:46:27 by rpinet            #+#    #+#             */
/*   Updated: 2014/11/26 16:46:31 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim_left(char const *s, size_t n)
{
	char	*str;

	if (!s || !*s)
		return ((char *)s);
	if (n > ft_strlen(s))
		return ("");
	str = ft_strdup(s + n);
	//free(str);
	return (str);
}
