/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft_shellcolors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 14:32:33 by rpinet            #+#    #+#             */
/*   Updated: 2015/02/20 14:32:56 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_minishell1.h"

#define FG_COLOR_TYPE "38;5"
#define BG_COLOR_TYPE "48;5"

static void	setcolor(t_uchar color, const char *type)
{
	char	*color_str;

	color_str = ft_itoa(color);
	ft_putstr("\033[");
	ft_putstr(type);
	ft_putchar(';');
	ft_putstr(color_str);
	ft_putchar('m');
}

void		ft_setfgcolor(t_uchar color)
{
	setcolor(color, FG_COLOR_TYPE);
}

void		ft_setbgcolor(t_uchar color)
{
	setcolor(color, BG_COLOR_TYPE);
}

void		ft_resetcolor(void)
{
	ft_putstr("\033[0m");
}
