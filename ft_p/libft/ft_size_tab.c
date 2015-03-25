/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 20:38:59 by rpinet            #+#    #+#             */
/*   Updated: 2015/02/24 20:39:21 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_size_tab(char **env)
{
	int			size;

	size = 0;
	while (env && *env++)
		size++;
	return (size);
}
