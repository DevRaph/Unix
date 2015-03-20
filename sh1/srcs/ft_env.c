/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <rpinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 20:37:41 by rpinet            #+#    #+#             */
/*   Updated: 2015/03/20 17:06:09 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_minishell1.h"

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
			if (!ft_strncmp(env[i], cmd[0][j], ft_size_id(cmd[0][j], "=") + 1))
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

void			ft_env_builtin1(char **env, char **cmd)
{
	int			size;
	int			nb;

	nb = 0;
	size = 0;
	while (cmd && cmd[size] && ft_strcmp(cmd[size++], "\0"))
		if (ft_strchr(cmd[size], '='))
			nb++;
	if (nb == (ft_size_tab(cmd) - 1))
	{
		ft_print_env(env, &cmd);
		ft_print_check(cmd);
	}
	else
	{
		if (!ft_strncmp(*(cmd + nb + 1), "/", 1) ||
			!ft_strncmp(*(cmd + nb + 1), "./", 2))
			ft_exec(env, cmd + nb + 1);
		else if (!ft_strncmp(*(cmd + nb + 1), "cd", 1))
			ft_exec_cd(env, cmd + nb + 1);
		else
			ft_exec_cmd(env, cmd + nb + 1);
	}
}

void			ft_env_builtin2(char **env, char **cmd)
{
	int			size;
	int			nb;

	nb = 0;
	size = 0;
	while (cmd && cmd[size] && ft_strcmp(cmd[size++], "\0"))
		if (ft_strchr(cmd[size], '='))
			nb++;
	if (nb == (ft_size_tab(cmd) - 2))
	{
		ft_print_env(NULL, &cmd);
		ft_print_check(cmd + 1);
	}
	else
	{
		if (!ft_strncmp(*(cmd + nb + 2), "/", 1) ||
			!ft_strncmp(*(cmd + nb + 2), "./", 2))
			ft_exec(NULL, cmd + nb + 2);
		else if (ft_strncmp(*(cmd + nb + 2), "cd", 1))
			ft_exec_cmd(NULL, cmd + nb + 2);
	}
	(void)env;
}

void			ft_env(char **env, char **cmd)
{
	if (*cmd && !*(cmd + 1))
		ft_print_tab(env);
	else if (*cmd && !ft_strcmp(*(cmd + 1), "-i"))
	{
		if (*(cmd + 2))
			ft_env_builtin2(env, cmd);
	}
	else
		ft_env_builtin1(env, cmd);
}
