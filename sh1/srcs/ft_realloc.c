/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 22:40:32 by marvin            #+#    #+#             */
/*   Updated: 2015/02/17 22:40:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	*ft_realloc(void *ptr, size_t old, size_t size)
{
	void	*new;

	if (ptr == NULL)
		return (NULL);
	if ((new = (void *)ft_memalloc((!size) ? sizeof(char) : size)) == NULL)
		return (NULL);
	ft_bzero(new, (!size) ? sizeof(char) : size);
	if (old > size)
		ft_memcpy(new, ptr, (!size) ? sizeof(char) : size);
	else
		ft_memcpy(new, ptr, old);
	ft_memdel((void *)&ptr);
	return (new);
}
