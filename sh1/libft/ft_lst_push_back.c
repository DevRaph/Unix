/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 16:01:04 by rpinet            #+#    #+#             */
/*   Updated: 2014/12/03 16:01:10 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		**ft_lst_push_back(t_list **my_list, t_list *elem)
{
	t_list	*ptr;

	if (!(ptr = *my_list) && !elem)
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = elem;
	}
	return (my_list);
}
