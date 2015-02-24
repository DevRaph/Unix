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

int				ft_size_tab(char **env)
{
	int			size;

	size = 0;
	while (env && *env++)
		size++;
	return (size);
}

#include <stdio.h>

static char		**ft_add_line(char **env, char *name, char *value)
{
	int			size;
	char		**save;
	char		**ptr;
	int			i;

	if (env && *env && name && value)
	{
		size = ft_size_tab(env); //taille max de env
		//ft_putendl("taille tableau :");
		//ft_putnbr(size);
		write (1, "\n", 1);
		if ((save = (char **)malloc(sizeof(char *) * size + 1)))
		{
		//ft_putendl("coucou");
			ptr = env;
			i = -1;
			while (ft_strcmp(ptr[++i], "\0")) // <= size ?
			{
				//printf("env[%d]%s\n", i, ptr[i]);
				save[i] = ft_strdup(ptr[i]);
				//printf("save[%d]%s\n", i, save[i]);
			}
			save[i++] = ft_strjoin(ft_strjoin(name, "="), value);
			save[i] = ft_strdup("\0");
		}
		ft_print_tab(save);

		/*i = 0;
		while (i < size)
			ft_strclr(*env[i++]);
		free(*env);
		if ((*env = (char **)malloc(sizeof(char *) * size + 2)))
		{
			ptr = save;
			*env[1] = ft_strdup(ptr[1]);
			i = -1;
			while (++i < size) // <= size ?
			{
				printf("save[%d]%s\n\tenv[%d]%s\n", i, ptr[i], i, *env[i]);
				*env[i] = ft_strdup(ptr[i]);
				printf("new env[%d]%s\n", i, *env[i]);
			}
			*env[i++] = ft_strjoin(ft_strjoin(name, "="), value);
			*env[i] = ft_strdup("\0");
		}*/

	ft_strdel(ptr);
	return (save);
	}
	else
		return (env);
}
/*
static char		**ft_add_line(char ***env, char *name, char *value)
{
	int			size;
	char		**save;
	char		**ptr;
	int			i;

	size = ft_size_tab(env); //taille max de env
	if (env && *env)
	{
		if (!(save = (char **)malloc(sizeof(char *) * size + 2)))
			return (NULL);
		ptr = env;
		i = 0;
		while (i < size)
			save[i++] = ft_strdup(*ptr++);
		save[i] = ft_strjoin(ft_strjoin(name, "="), value);
		save[i++] = ft_strdup("\0");
	}
	ft_strdel(ptr);
	return (save);
}*/

void			ft_setenv(char *name, char *value, int o, char ***env)
{
	char		**ptr;

	if (env && *env && name && value)// gerer taille max de l'env + 1 ou 0 pour overite
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

void			ft_unsetenv(char *name, char ***env)
{
	char		**ptr;
	char		*str;
	char		ok;

	ptr = *env;
	ok = 'o';
	while (ptr && *ptr && name)
	{
		if (!ft_strncmp(*ptr, name, ft_strlen(name)))
			ok = 'k';
		if (ok == 'k')
		{
			ft_strclr(*ptr);
			if (*(ptr + 1))
				*ptr = ft_strdup(*(ptr + 1));
			else
				*ptr = ft_strdup("\0");
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

// gerer + deux valeur et affichage de env segfault
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
			ft_print_tab(env);
			size = 1; // possible amelioration check si deja affiche reafficher par dessus option du printenv
			while (*cmd &&cmd[size++] != NULL)
				ft_putendl(cmd[size - 1]);
		}
		else
		{
			*cmd = ft_strdup(*(cmd + 1));
			ft_exec_cmd(env, cmd + 1);
		}
	}
}
