/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 11:52:11 by rpinet            #+#    #+#             */
/*   Updated: 2015/03/30 11:52:14 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../libft/libft.h"

void				ft_get(char **cmd)
{
	char			*str;

	// faire boucle sur les fichiers en parametre voir si arguments
	if (*(cmd + 1) && *(cmd + 2) && !*(cmd + 3))
	{
		str = getcwd(NULL, 1024);
		ft_putstr("exec get :\n\tclient :   ");
		ft_putstr(*cmd);
		ft_putstr("\n\tserveur : ");
		ft_putendl(str);
		ft_putstr("\tfile :    ");
		ft_putstr(*(cmd + 2));
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
