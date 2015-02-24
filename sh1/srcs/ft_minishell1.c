/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 16:05:43 by rpinet            #+#    #+#             */
/*   Updated: 2015/02/19 21:37:37 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_minishell1.h"
#include <sys/types.h>
#include <sys/wait.h>

/* taille tableau
   malloc a taille + 1
   transfert
   suppression (strclr + free du env)
   retour tab*/



void		ft_prompt(char **env, char *str)
{
	char	*pos;

	ft_setfgcolor(33);
	write (1, "    [", 5);
	ft_resetcolor();
	if (env && ft_get_env(env, "USER") != NULL)
		ft_putstr(ft_strjoin(ft_get_env(env, "USER") + 5, " --> "));
	pos = getcwd(NULL, 1024);
	pos = pos + ft_strlen(pos);
	while (pos && (*(pos - 1) != '/'))
		pos--;
	if (pos)
		write (1, pos, ft_strlen(pos));
	ft_setfgcolor(33);
	write (1, "] $> ", 5);
	ft_resetcolor();
	if (str)
		write(1, str, ft_strlen(str));
}

void		ft_recup_signal(int signal)
{
	extern char		**environ;

	if (signal == SIGINT)
	{
		write(1, "\n", 1);
		ft_prompt(environ, "");
	}
	else if (signal == SIGSEGV)
	{
		ft_error("[recup_signal] :", " : segfault");
		ft_prompt(environ, "");
		ft_print_tab(environ);
		exit (0);
	}//ft_putendl(ft_itoa(signal));
}

void			ft_launch_shell(char ***env)
{
	char	*line;
	char	**cmd;
	char	**sep;

	ft_prompt(*env, "");
	while (get_next_line(0, &line) > 0)
	{
		if (line[0])
			sep = ft_strsplit(line, ';');
		while (sep && *sep++)
		{
			line = ft_clean(*(sep - 1));
			if (line && *line)
			{
				cmd = ft_strsplit(line, ' ');
				ft_setfgcolor(2);
				ft_builtin(env, cmd);
				ft_resetcolor();
			}
		}
		ft_prompt(*env, "");
	}
}

char		**ft_init_env(void)
{
	char	**env;

	if (!(env = (char **)malloc(sizeof(char *) * 5)))
		return (NULL);
	*env = ft_strjoin("HOME=", getcwd(NULL, 1024));
	*(env + 1) = ft_strjoin("PWD=", getcwd(NULL, 1024));
	*(env + 2) = ft_strjoin("OLDPWD=", getcwd(NULL, 1024));
	*(env + 3) = ft_strjoin("USER=", " -mode debug- ");
	*(env + 4) = ft_strdup("\0");
	return (env);
}

int			ft_minishell1(char **environ)
{
	int		size;
	char	**env;
	int		i;

	if (environ == NULL || *environ == NULL)
	{
		env = ft_init_env();
		if (env == NULL)
			return (1);
		else
		ft_launch_shell(&env);
	}
	else
	{
		size = ft_size_tab(environ);
		if (!(env = (char **)malloc(sizeof(char *) * size + 1)))
			return (1);
		i = 0;
		while (environ && *environ++)
			env[i++] = ft_strdup(*(environ - 1));
		env[i] = ft_strdup("\0");
		ft_launch_shell(&env);
	}
	return (0);
}
