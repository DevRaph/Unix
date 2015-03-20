/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <rpinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 22:03:41 by rpinet            #+#    #+#             */
/*   Updated: 2015/03/20 16:52:45 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_minishell1.h"

static char		**ft_add_line(char **env, char *name, char *value)
{
	int			size;
	char		**save;
	char		**ptr;
	int			i;

	ptr = NULL;
	if (env && *env && name && value)
	{
		size = ft_size_tab(env);
		if ((save = (char **)malloc(sizeof(char *) * size + 2)))
		{
			ptr = env;
			i = -1;
			while (env && *env && ft_strcmp(ptr[++i], "\0"))
				save[i] = ft_strdup(ptr[i]);
			save[i++] = ft_strjoin(ft_strjoin(name, "="), value);
			save[i] = ft_strdup("\0");
		}
		ft_strdel(ptr); // a tester
		return (save);
	}
	else
		return (env);
}

void			ft_setenv(char *name, char *value, int o, char ***env)
{
	char		**ptr;
	char		*str;

	if (env && *env && name && value)
	{
		if (ft_strchr(name, '=') != NULL)
			ft_error("setenv", "name contain '='");
		else
		{
			if (ft_get_env(*env, name) == NULL)
				*env = ft_add_line(*env, name, value);
			if (ft_get_env(*env, name) != NULL && o != 0)
			{
				ptr = *env;
				str = ft_strjoin(name, "=");
				while (*ptr && ft_strncmp(*ptr, str, ft_strlen(name) + 1) != 0)
					ptr++;
				*ptr = ft_strjoin(ft_strjoin(name, "="), value);
			}
		}
	}
	else if (env && *env && !ft_strcmp(**env, "\0") && name && value)
		*env[0] = ft_strjoin(ft_strjoin(name, "="), value);
}
