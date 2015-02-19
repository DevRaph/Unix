/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 15:11:22 by rpinet            #+#    #+#             */
/*   Updated: 2015/01/06 15:11:42 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_atoi_base(char *s, int b)
{
	int		abs;
	int		total;
	int		i;
	char	*base;

	i = 0;
	s = ft_strdup(s);
	base = ft_get_base(b);
	while (ft_isspace(*(s + i)))
		i++;
	abs = 1;
	if (*s == '-')
		abs = -1 * (*(s + i++) == '-');
	else if (*(s + i) == '+')
		i++;
	total = 0;
	while (ft_strpos(base, *(s + i)) != ~(!abs))
		total = total * ft_strlen(base) + ft_strpos(base, *(s + i++));
	free(s);
	free(base);
	return (total * abs);
}
