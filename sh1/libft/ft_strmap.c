/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 18:37:07 by rpinet            #+#    #+#             */
/*   Updated: 2014/11/10 19:01:05 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	char	*ptr;

	if (!s || !f || !(str = ft_strnew(ft_strlen(s))))
		return (NULL);
	ptr = str;
	while (s && *s && f)
		*ptr++ = f(*s++);
	return (str);
}
