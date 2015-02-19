/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 17:11:14 by rpinet            #+#    #+#             */
/*   Updated: 2015/02/12 17:13:33 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>

int			ft_error(char *s, char *s2)
{
	//write(1, "  ", 2);
	//perror(s); // interdit
	if (s)
	{
		//write(1, "  gestion erreur perso :\n", 25);
		write(1, "-->", 3);
		write(1, s, ft_strlen(s));
		if (s2)
			write(1, s2, ft_strlen(s2));
		write (1, "\n", 1);
	}
	return (0);
}
