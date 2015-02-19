/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 13:21:03 by rpinet            #+#    #+#             */
/*   Updated: 2014/11/11 16:10:44 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
/*
char	*ft_itoa(int n)
{
	char *p;

	p = ft_strnew((int)ft_nbrlen(10)) + (int)ft_nbrlen(10);
	if (n >= 0 && p)
	{
		*--p = '0' + (n % 10);
		while ((n /= 10) != 0)
			*--p = '0' + (n % 10);
	}
	else if (p)
	{
		*--p = '0' - (n % 10);
		while ((n /= 10) != 0)
			*--p = '0' - (n % 10);
		*--p = '-';
	}
	return (p);
}*/

char	*ft_itoa(int n)
{
	int		negative;
	char	*s;

	negative = (n < 0) ? 1 : 0;
	if (n == -2147483648)
		return ("-2147483648");
	if (!n)
		return ("0");
	if (!(s = ft_strnew(20)))
		return (NULL);
	s += 18;
	while (n != 0)
	{
		*s-- = '0' + ft_abs(n % 10);
		n /= 10;
	}
	if (negative)
		*s = '-';
	return (s + !negative);
}
