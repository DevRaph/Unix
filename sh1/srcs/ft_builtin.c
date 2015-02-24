/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 22:13:24 by rpinet            #+#    #+#             */
/*   Updated: 2015/02/19 21:36:18 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell1.h"
#include "../libft/libft.h"
#include "../includes/ft_minishell1.h"
#include "../libft/libft.h"

//debug
void		ft_print_cmd(char **cmd)
{
	write (1, "cmd=", 4);
	write (1, *cmd, ft_strlen(*cmd));
	write (1, " opt=", 5);
	while (cmd && *cmd++)
	{
		write (1, *cmd, ft_strlen(*cmd));
		write (1, " ", 1);
	}
	write (1, "\n", 1);
}

char		*ft_get_env(char **env, char *id)
{
	char	*pos;

	while (env && *env && ft_strcmp(*env, "\0") != 0)
	{
		if (!ft_strncmp(*env, id, ft_strlen(id)))
		{
			pos = ft_strdup(*env);
			return (pos);
		}
		env++;
	}
	return (NULL);
}

char		*ft_clean(char *s)
{
	char	*str;
	char	*ptr;

	if (!(str = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	ptr = str;
	while (s && *s)
	{
		if (ft_isspace(*s))
		{
			if (s + 1 && *(s + 1) && !ft_isspace(*(s + 1)))
				*ptr++ = ' ';
		}
		else
			*ptr++ = *s;
		s++;
	}
	str = ft_strtrim(str);
	return (str);
}

void		ft_builtin(char ***env, char **cmd)
{
	if (!ft_strcmp(*cmd, "env"))
		ft_env(*env, cmd);
	else if (!ft_strcmp(*cmd, "setenv"))
	{
		if (*(cmd + 1) && *(cmd + 2))
			ft_setenv(cmd[1], cmd[2], 1, env);
		else
			ft_error("[builtin] :", " : setenv bad argument");
	}
	else if (!ft_strcmp(*cmd, "unsetenv"))
	{
		if (*(cmd + 1))
			ft_unsetenv(cmd[1], env);
		else
			ft_error("[builtin] :", " : unsetenv bad argument");
	}
	else if (!ft_strcmp(*cmd, "cd"))
		ft_exec_cd(*env, cmd);
	else if (!ft_strncmp(*cmd, "/", 1) || !ft_strncmp(*cmd, "./", 2))
		ft_exec(*env, cmd);
	else if (!ft_strcmp(*cmd, "exit"))
		exit(0);
	else
		ft_exec_cmd(*env, cmd);
}
