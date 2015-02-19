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
   retour tab
   ... bonus ...
   "cd " !!! home attention si pas de home (gestion)
   si env -i creer un env
   > PATH=/bin:/opt/X11
   > HOME= (getcwd)
   > PWD= (getcwd)
   > OLD= (getcwd)-1*/

void		ft_prompt(char **env, char *str)
{
	char	*pos;

	//pos = ft_get_env(env, "PWD");
	(void)env;
	pos = getcwd(NULL, 1024);
	pos = pos + ft_strlen(pos);
	while (pos && (*(pos - 1) != '/'))
		pos--;
	write (1, "    [", 5);
	if (pos)
		write (1, pos, ft_strlen(pos));
	write (1, "] $> ", 5);
	if (str)
		write(1, str, ft_strlen(str));
}

void		ft_recup_signal(int signal)
{
	extern char		**environ;  // controle c plus pris en compte ???

	write(1, "\n", 1);
	ft_prompt(environ, "");
	(void)signal;
}

int			ft_launch_shell(char **env)
{
	char	*line;
	char	**cmd;
	int		ret; // a virer pour surveiller les retour de fork

	ret = 1234;
	write (1, "*Father\n", 8);
	ft_prompt(env, "");
	while (get_next_line(0, &line) > 0)
	{
		line = ft_clean(line);
		if (line[0])
		{
			cmd = ft_strsplit(line, ' ');
			env = ft_builtin(env, cmd);
		}
		if (signal(SIGINT, ft_recup_signal) == SIG_ERR)
			ft_error("[ft_launch_shell] :", " : signal error");
		else
			ft_prompt(env, "");
	}
	return (ret);
}

char		**ft_init_env(void)
{
	char	**env;

	if (!(env = (char **)malloc(sizeof(char *) * 3)))
		return (NULL);
	env[0] = ft_strjoin("HOME=", getcwd(NULL, 1024));
	env[1] = ft_strjoin("PWD=", getcwd(NULL, 1024));
	env[2] = ft_strjoin("OLDPWD=", getcwd(NULL, 1024));
	//ft_print_tab(env); //mauvaise initialisation
	ft_launch_shell(env);
	return (env);
}

int			ft_minishell1(char **av, char **env)
{
	if (env == NULL || *env == NULL)
	{
		write(1, "coucou\n", 7);
		env = ft_init_env();
		if (env == NULL)
			return (1);
	}
	else
		ft_launch_shell(env);
	(void)av;
	return (0);
}
