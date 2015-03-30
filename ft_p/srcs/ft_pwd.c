/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 11:52:28 by rpinet            #+#    #+#             */
/*   Updated: 2015/03/30 11:53:43 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// faire -L -P
// getcwd autorisee ???
#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft.h"

void				ft_pwd(char **cmd)
{
	char			*str;

	str = getcwd(NULL, 1024);
	if (*(cmd + 1) && !*(cmd + 2))
		ft_putendl(str);
	else if (*(cmd + 2) && !*(cmd + 3))
	{
		if (!ft_strncmp(*(cmd + 2), "-L", 2) || !ft_strncmp(*(cmd + 2), "-P", 2))
			ft_putendl("option of pwd -L or -P");
	}
	else
	{
		ft_error("pwd", "bad arguments");
	}
	//free(str);
}
