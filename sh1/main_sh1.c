/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sh1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 16:16:12 by rpinet            #+#    #+#             */
/*   Updated: 2015/02/19 21:35:48 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "includes/ft_minishell1.h"
#include <stdlib.h>

int		main(int ac, char **av)
{
	extern char		**environ;

	if (ac > 1)
		return (ft_error("[Main] :", " : no argument in ft_minishell1"));
	if (!ft_minishell1(av, environ) && ac)
		ft_putendl("*******launch OK\n");
	else
		exit (ft_error("[Main] : ", ": error launch shell\n"));
	return (0);
}
