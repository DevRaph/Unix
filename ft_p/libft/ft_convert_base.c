/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 15:07:28 by rpinet            #+#    #+#             */
/*   Updated: 2015/01/06 15:08:32 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_convert_base(char *nbr, int bf, int bt)
{
	int		i;
	char	*res;
	int		convert;
	char	*base_to;

	i = 0;
	res = ft_strnew(64);
	base_to = ft_get_base(bt);
	convert = ft_atoi_base(nbr, bf);
	while (convert > 0)
	{
		*(res + i++) = base_to[convert % ft_strlen(base_to)];
		convert /= ft_strlen(base_to);
	}
	*(res + i++) = '\0';
	free(base_to);
	free(res);
	return (ft_strrev(res));
}
