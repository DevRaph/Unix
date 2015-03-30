/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 11:51:58 by rpinet            #+#    #+#             */
/*   Updated: 2015/03/30 11:52:00 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../libft/libft.h"

void				ft_put(char **cmd)
{
	char			*str;

	// faire boucle sur les fichiers en parametre voir si arguments
	if (*(cmd + 1) && *(cmd + 2) && !*(cmd + 3))
	{
		str = getcwd(NULL, 1024);
		ft_putstr("exec put :\n\tclient :   ");
		ft_putstr(*cmd);
		ft_putstr("\n\tserveur : ");
		ft_putendl(str);
		ft_putstr("\tfile :    ");
		ft_putendl(*(cmd + 2));
	}
	else
	{
		ft_putstr("\b");
		if (*(cmd + 3))
			ft_error("put", "more than one file in dev ...");
		else
			ft_error("put", " bad parameters");
	}
}
