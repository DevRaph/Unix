/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 22:03:41 by rpinet            #+#    #+#             */
/*   Updated: 2015/02/24 22:12:44 by rpinet           ###   ########.fr       */
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

	if (env && *env && name && value)
	{
		size = ft_size_tab(env);
		if ((save = (char **)malloc(sizeof(char *) * size + 1)))
		{
			ptr = env;
			i = -1;
			while (ft_strcmp(ptr[++i], "\0"))// <= size ?
				save[i] = ft_strdup(ptr[i]);
			save[i++] = ft_strjoin(ft_strjoin(name, "="), value);
			save[i] = ft_strdup("\0");
		}
		ft_strdel(ptr);
		return (save);
	}
	else
		return (env);
}
// gerer taille max de l'env 1024 + 1 ou 0 pour overite
void			ft_setenv(char *name, char *value, int o, char ***env)
{
	char		**ptr;

	if (env && *env && name && value)
	{
		if (ft_strchr(name, '=') != NULL)
			ft_error("[setenv] :", " : name contain '='");
		else
		{
			if (ft_get_env(*env, name) == NULL)
				*env = ft_add_line(*env, name, value);
			if (ft_get_env(*env, name) != NULL && o != 0)
			{
				ptr = *env;
				while (*ptr && ft_strncmp(*ptr, name, ft_strlen(name)) != 0)
					ptr++;
				*ptr = ft_strjoin(ft_strjoin(name, "="), value);
			}
		}
	}
}
