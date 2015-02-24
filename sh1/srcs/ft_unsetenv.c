/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 22:03:25 by rpinet            #+#    #+#             */
/*   Updated: 2015/02/24 22:12:53 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_minishell1.h"

void			ft_unsetenv(char *name, char ***env)
{
	char		**ptr;
	char		*str;
	char		ok;

	ptr = *env;
	ok = 'o';
	while (ptr && *ptr && name && ft_strcmp(*ptr, "\0"))
	{
		str = ft_strdup(name);
		if (!ft_strncmp(*ptr, ft_strjoin(name, "="), ft_strlen(name) + 1))
			ok = 'k';
		if (ok == 'k')
		{
			ft_strclr(*ptr);
			*ptr = ft_strdup((*(ptr + 1) && ptr + 1) ? *(ptr + 1) : "\0");
		}
		ptr++;
	}
	if (ok == 'o')
	{
		str = ft_strjoin(" : no found ", name);
		str = ft_strjoin(str, " in environment");
		ft_error("[unsetenv] :", str);
	}
}
