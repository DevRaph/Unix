/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <rpinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 14:50:18 by rpinet            #+#    #+#             */
/*   Updated: 2015/03/20 15:21:28 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_minishell1.h"

void			ft_exit(char **cmd)
{
	if (*cmd && *(cmd + 1) && *(cmd + 2))
		ft_error("exit", "too many arguments");
	else if (*cmd && *(cmd + 1))
	{
		if (ft_isnb(*(cmd + 1)))
			exit (ft_atoi(*(cmd + 1)));
		else
			ft_error("exit", "just numerics arguments");
	}
	else if (*cmd && *(cmd + 1) == NULL)
		exit (0);
}

