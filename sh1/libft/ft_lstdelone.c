/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 14:49:08 by rpinet            #+#    #+#             */
/*   Updated: 2015/02/05 19:29:08 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (alst != NULL && *alst != NULL && (*del) != NULL)
	{
		(*del)((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = NULL;
	}
}
