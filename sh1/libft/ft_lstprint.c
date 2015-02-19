/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 16:24:57 by rpinet            #+#    #+#             */
/*   Updated: 2014/12/03 16:24:58 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list **my_list)
{
	t_list	*ptr;

	if (!(ptr = *my_list))
	{
		ft_putchar('\n');
		while (ptr->next)
		{
			ft_putchar('[');
			ft_putstr((char *)ptr->content);
			ft_putstr("] ");
			ptr = ptr->next;
		}
		ft_putchar('\n');
	}
}
