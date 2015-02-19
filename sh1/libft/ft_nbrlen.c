/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 16:50:19 by rpinet            #+#    #+#             */
/*   Updated: 2014/11/26 17:01:10 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_nbrlen(int nb)
{
	int i;

	if (nb < 0)
		nb = -(nb);
	i = 0;
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}
