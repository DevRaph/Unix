/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 20:37:41 by rpinet            #+#    #+#             */
/*   Updated: 2015/02/24 22:11:28 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_minishell1.h"

// corriger ft_size_word dans libft et ft_strsplit
size_t			ft_size_id(char const *s, char *c)
{
	int			size;

	if (!s || !*s || !c)
		return (0);
	size = 0;
	while (ft_strncmp(s, c, (size_t)ft_strlen(c)) != 0 && *s != '\0')
	{
		s++;
		size++;
	}
	return (size);
}

void			ft_print_env(char **env, char ***cmd)
{
	int			i;
	int			j;
	int			ok;

	i = -1;
	while (env && env[++i] != NULL && env[i][0] != '\0')
	{
		j = ft_size_tab(*cmd);
		ok = 0;
		while (--j > 0)
		{
			if (!ft_strncmp(env[i], cmd[0][j], ft_size_id(cmd[0][j], "=")))
			{
				if (!ok)
					ft_putendl(cmd[0][j]);
				cmd[0][j] = ft_strdup("\n");
				ok = 1;
			}
		}
		if (!ok)
			ft_putendl(env[i]);
	}
}

void			ft_print_check(char **cmd)
{
	int			i;
	int			size;
	int			ok;
	int			l;

	size = 0;
	while (*cmd && cmd[++size] != NULL)
	{
		ok = 0;
		i = 1;
		while (*cmd && cmd[size + i] != NULL)
		{
			l = ft_size_id(cmd[size + i], "=");
			if (!ft_strncmp(cmd[size], cmd[size + i], l))
				ok = 1;
			i++;
		}
		if (ft_strcmp(cmd[size], "\n") && ok == 0)
			ft_putendl(cmd[size]);
	}
}

void			ft_env(char **env, char **cmd)
{
	int			size;
	int			nb;

	if (*cmd && !*(cmd + 1))
		ft_print_tab(env);
	else
	{
		nb = 0;
		size = 0;
		while (cmd && cmd[size++] != NULL)
			if (ft_strchr(cmd[size], '='))
				nb++;
		if ((nb + 1) == ft_size_tab(cmd))
		{
			ft_print_env(env, &cmd);
			ft_print_check(cmd);
		}
		else
		{
			*cmd = ft_strdup(*(cmd + 1));
			ft_exec_cmd(env, cmd + 1);
		}
	}
}
