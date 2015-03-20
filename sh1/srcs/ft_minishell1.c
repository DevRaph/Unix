/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <rpinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 16:05:43 by rpinet            #+#    #+#             */
/*   Updated: 2015/03/20 17:33:01 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_minishell1.h"
#include <sys/types.h>
#include <sys/wait.h>

void			ft_prompt(char **env, char *str)
{
	char		*pos;

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
	ft_strclr(pos);
}

void			ft_launch_shell(char ***env)
{
	char		*line;
	char		**cmd;
	char		**sep;

	ft_prompt(*env, "");
	while (get_next_line(0, &line) > 0)
	{
		if (line[0])
		{
			line = ft_clean(line);
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
		}
		ft_strclr(line); // possible segfault
		ft_prompt(*env, "");
	}
}

static char			**ft_init_env(void)
{
	char		**env;
	char		*str;

	if (!(env = (char **)malloc(sizeof(char *) * 5)))
		return (NULL);
	str = getcwd(NULL, 1024);
	*env = ft_strjoin("HOME=", str);
	*(env + 1) = ft_strjoin("PWD=", str);
	*(env + 2) = ft_strjoin("OLDPWD=", str);
	*(env + 3) = ft_strjoin("USER=", " -mode debug- ");
	*(env + 4) = ft_strdup("\0");
	free(str);
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
	ft_strdel(env);
	return (0);
}

int				ft_exec(char **env, char **cmd)
{
	int			status;
	pid_t		pid;
	int			ok;
	char		*str;
	extern char	**environ;

	pid = fork();
	if (pid == 0 && cmd && cmd[0])
	{
		ok = 1;
		if (cmd && cmd[0] && (execve (cmd[0], cmd, environ)) != -1)
			ok = 0;
		if (ok == 1)
		{
			str = ft_strjoin("command not found: ", cmd[0]);
			ft_error("exec_cmd", str);
			ft_strdel(&str);
		}
		exit(0);
	}
	else if (pid < 0)
		ft_error("exec_cmd", "fork failed\n");
	waitpid(pid, &status, 0);
	(void)env;
	return (status);
}
