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

void			ft_unset_all(char ***env)
{
	char		**ptr;

	ptr = *env;
	while (ptr && *ptr && ft_strcmp(*ptr++, "\0"))
	{
		ft_strclr(*(ptr - 1));
	}
}

void			ft_unsetenv(char *name, char ***env)
{
	char		**ptr;
	char		*str;
	char		ok;

	ptr = *env;
	ok = 'o';
	while (ptr && *ptr++ && name && ft_strcmp(*(ptr - 1), "\0"))
	{
		str = ft_strdup(name);
		if (!ft_strncmp(*(ptr - 1), ft_strjoin(name, "="), ft_strlen(name) + 1))
			ok = 'k';
		if (ok == 'k')
		{
			ft_strclr(*(ptr - 1));
			*(ptr - 1) = ft_strdup((*(ptr) && (ptr)) ? *(ptr) : "\0");
		}
	}
	if (!ft_strcmp(name, "*"))
		ft_unset_all(env);
	if (ok == 'o' && ft_strcmp(name, "*"))
	{
		str = ft_strjoin(" : no found ", name);
		str = ft_strjoin(str, " in environment");
		ft_error("[unsetenv] :", str);
	}
}
