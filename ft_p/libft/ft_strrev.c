/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 10:55:15 by rpinet            #+#    #+#             */
/*   Updated: 2014/11/26 14:12:02 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strrev(char *str)
{
	int		lenght;
	char	temp;
	int		i;

	if (!str || !*str)
		return (str);
	lenght = ft_strlen(str);
	i = -1;
	while (--lenght > ++i)
	{
		temp = str[lenght];
		str[lenght] = str[i];
		str[i] = temp;
	}
	return (str);
}
