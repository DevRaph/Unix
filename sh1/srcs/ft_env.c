/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 20:37:41 by rpinet            #+#    #+#             */
/*   Updated: 2015/02/19 21:36:33 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_minishell1.h"

int			ft_size_tab(char **env)
{
	int		size;

	size = 0;
	while (env && *env++)
		size++;
	return (size);
}

static char		**ft_add_line(char **env, const char *name, const char *value)
{
	int		size;
	char	**save;
	char	**ptr;

	size = ft_size_tab(env);
	if (env)
	{
		if (!(save = (char **)malloc(sizeof(char *) * size + 1)))
			return (NULL);
		ptr = env;
		int i = 0;
		while (i < size)
			save[i++] = ft_strdup(*ptr++);
		save[size] = ft_strjoin(ft_strjoin(name, "="), value);
		//save[size + 1] = ft_strdup("\0");
	}
	ft_strdel(ptr);
	return (save);
}

char		**ft_setenv(const char *name, const char *value, int o, char **env)
{
	char	**ptr;

	if (!env || !name) // gerer taille max de l'env
		return (env);
	if (ft_strchr(name, '=') != NULL)
	{
		ft_error("[setenv] :", " : name contain '='");
		return(env);
	}
	if (ft_get_env(env, (char *)name) == NULL)
		env = ft_add_line(env, name, value);
	if (ft_get_env(env, (char *)name) != NULL && o != 0)
	{
		ptr = env;
		while (*ptr && ft_strncmp(*ptr, (char *)name, ft_strlen(name)) != 0)
			ptr++;
		*ptr = ft_strjoin(ft_strjoin(name, "="), value);
	}
	return (env);
}

char		**ft_unsetenv(const char *name, char **env)
{
	char	**ptr;

	ptr = env;
	while (*ptr && ft_strncmp(*ptr, (char *)name, ft_strlen(name)) != 0)
		ptr++;
	ft_strdel(ptr);
	return (env);
}

void		ft_env(char **env, char **cmd)  // gerer + deux valeur et affichage de env segfault
{
	if (*cmd && !*(cmd + 1))
		ft_print_tab(env);
	else if (*cmd && *(cmd + 1) && !*(cmd + 2))
	{
		ft_print_tab(env);
		ft_putendl(*(cmd + 1));
	}
	else
		ft_error("[env] :", " : No such file or directory");
}
