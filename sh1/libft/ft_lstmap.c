/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 18:53:02 by rpinet            #+#    #+#             */
/*   Updated: 2015/02/05 19:10:31 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ptr;
	t_list	*new_elem;
	t_list	*ret;
	t_list	*end;

	ptr = lst;
	if ((*f))
	{
		while (ptr)
		{
			new_elem = ft_lstnew(ptr->content, ptr->content_size);
			new_elem = (*f)(new_elem);
			if (ptr == lst)
			{
				ret = new_elem;
				end = new_elem;
			}
			else
			{
				end->next = new_elem;
				end = new_elem;
			}
			ptr = ptr->next;
		}
	}
	return (ret);
}
