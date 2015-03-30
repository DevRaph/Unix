/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 11:53:56 by rpinet            #+#    #+#             */
/*   Updated: 2015/03/30 12:59:12 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_p.h"

void			ft_builtin(int cs, char **cmd)// supprimmer cs
{
	if (!ft_strncmp(*(cmd + 1), "ls", 2))
		ft_putendl("execv ls");
	else if (!ft_strncmp(*(cmd + 1), "cd", 2))
		ft_exec_cd(cmd);
	else if (!ft_strncmp(*(cmd + 1), "pwd", 3))// && ft_strlen(*(cmd + 1)) == 4)
		ft_pwd(cmd);
	else if (!ft_strncmp(*(cmd + 1), "put", 3))
		ft_put(cmd);
	else if (!ft_strncmp(*(cmd + 1), "get", 3))
		ft_get(cmd);
	else if (!ft_strncmp(*(cmd + 1), "quit", 4))
	{
		ft_putstr("\n\nx-x deconnexion du client, socket ");
		ft_putnbr(cs);
		ft_putendl(" x-x\n");
	}
	else
		//ft_putendl("xxx [builtin] : command not found");
		ft_error("builtin", "command not found");
	//exit(0);
}
