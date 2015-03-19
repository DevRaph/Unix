/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 15:25:44 by rpinet            #+#    #+#             */
/*   Updated: 2015/02/05 19:32:58 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*ret;

	if ((ret = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL || content_size == 0)
		return (NULL);
	ft_memcpy(ret->content, content, content_size);
	ret->content_size = content_size;
	ret->next = NULL;
	return (ret);
}
