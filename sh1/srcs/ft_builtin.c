/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <rpinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 22:13:24 by rpinet            #+#    #+#             */
/*   Updated: 2015/03/25 14:46:19 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell1.h"
#include "../libft/libft.h"

size_t		ft_size_id(char const *s, char *c)
{
	int		size;

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

char		*ft_join(char *path, char *cmd)
{
	char	*ret;

	if (!path)
		return (".");
	ret = ft_strjoin(path, "/");
	ret = ft_strjoin(ret, cmd);
	free (path);
	return (ret);
}

char		*ft_get_env(char **env, char *id)
{
	char	*pos;

	while (env && *env && ft_strcmp(*env, "\0") != 0)
	{
		pos = ft_strjoin(id, "=");
		if (!ft_strncmp(*env, pos, ft_strlen(id) + 1))
		{
			pos = ft_strdup(*env);
			return (*env);
		}
		ft_strdel(&pos);
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
		if (*(cmd + 1) && *(cmd + 2) && !*(cmd + 3))
			ft_setenv(cmd[1], cmd[2], 1, env);
		else
			ft_error("builtin", (*(cmd + 1)) ? TM_ARG : F_ARG);
	}
	else if (!ft_strcmp(*cmd, "unsetenv"))
	{
		if (*(cmd + 1))
			ft_unsetenv(cmd[1], env);
		else
			ft_error("builtin", "unsetenv bad arguments");
	}
	else if (!ft_strcmp(*cmd, "cd"))
		ft_exec_cd(*env, cmd);
	else if (!ft_strncmp(*cmd, "/", 1) || !ft_strncmp(*cmd, "./", 2))
		ft_exec(*env, cmd);
	else if (!ft_strcmp(*cmd, "exit"))
		ft_exit(cmd);
	else
		ft_exec_cmd(*env, cmd);
}
