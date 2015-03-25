/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 19:10:39 by rpinet            #+#    #+#             */
/*   Updated: 2014/11/10 19:23:22 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	char	*str;
	char	*ptr;

	if (!s || !(str = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	str = ft_strcpy(str, s);
	ptr = str;
	ptr += ft_strlen(str) - 1;
	while (*ptr == ' ' || *ptr == '\t' || *ptr == '\n')
		ptr--;
	*++ptr = '\0';
	return (str);
}
