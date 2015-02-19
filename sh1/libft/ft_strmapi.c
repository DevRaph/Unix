/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 18:37:07 by rpinet            #+#    #+#             */
/*   Updated: 2014/11/10 19:01:13 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	char			*ptr;
	unsigned int	i;

	if (!s || !f || !(str = ft_strnew(ft_strlen(s) + 1)))
		return (NULL);
	ptr = str;
	i = 0;
	while (s && *s && f)
		*ptr++ = (*f)(i++, *s++);
	return (str);
}
