/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 14:52:48 by rpinet            #+#    #+#             */
/*   Updated: 2015/02/05 19:30:17 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	/*t_list	*ptr;

	ptr = *alst;
	if ((*del) != NULL)
	{
		while (ptr->next != NULL)
		{
			(*del)(ptr->content, ptr->content_size);
			ft_lstdelone(&ptr);
			ptr = ptr->next;
		}
		free(ptr);
		free(*alst);
		*alst = NULL;
	}*/
	(void)**alst;
	(void)(*del);
}
