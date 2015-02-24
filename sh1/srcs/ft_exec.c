/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 20:42:30 by rpinet            #+#    #+#             */
/*   Updated: 2015/02/24 22:11:46 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_minishell1.h"

int				ft_exec_cmd(char **env, char **cmd)
{
	int			status;
	pid_t		pid;
	char		**path;
	int			ok;
	extern char	**environ;

	path = NULL;
	ok = -1;
	while (cmd[0] && env && *env && ft_strcmp(env[++ok], "\0"))// test -cmd[0]
		if (!ft_strncmp(env[ok], "PATH", 4))
			path = ft_strsplit(env[ok] + 5, ':');
	pid = fork();
	if (pid == 0)
	{
		if (cmd == NULL || cmd[0] == NULL || !ft_strcmp(cmd[0], ""))
			exit (0);
		ok = 1;
		while (path && *path)
			if (execve (ft_join(*path++, cmd[0]), cmd, environ) != -1)
				ok = 0;
		if (ok == 1)
			ft_error("[exec_cmd]", ft_strjoin("command not found: ", cmd[0]));
		exit(0);
	}
	else if (pid < 0)
		ft_error("\n[exec_cmd] :", " : fork failed\n");
	waitpid(pid, &status, 0);
	//ft_memdel((void **)path);
	return (status);
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
			str = ft_strjoin(" command not found: ", cmd[0]);
			ft_error("[exec_cmd] :", str);
		}
		exit(0);
	}
	else if (pid < 0)
		ft_error("\n[exec_cmd] :", " : fork failed\n");
	waitpid(pid, &status, 0);
	(void)env;
	return (status);
}
//amelioration avec clean path
static char		*ft_contruct_path(char **env, char **cmd)
{
	char		*path;
	char		*str;

	str = getcwd(NULL, 1024);
	if (!*(cmd + 1) || !ft_strncmp(*(cmd + 1), "~", 1))
	{
		if (env != NULL || ft_get_env(env, "HOME") != NULL)
			path = ft_get_env(env, "HOME") + 5;
	}
	else if (!ft_strncmp(*(cmd + 1), "-", 1) && ft_get_env(env, "OLDPWD"))
	{
		path = ft_strdup(ft_get_env(env, "OLDPWD") + 7);
		ft_putendl(str);
	}
	else if (!ft_strncmp(*(cmd + 1), "/", 1))
		path = ft_strdup(*(cmd + 1));
	//else if (!ft_strncmp(*(cmd + 1), "./.", 3))
	//	path = ft_strdup(str);
	//else if (!ft_strncmp(*(cmd + 1), "./", 2))
	//	path = ft_join(str, *(cmd + 1) + 2);
	else
		path = ft_join(str, *(cmd + 1));
	return (path);
}
// possible amelioration avec ajout de OLDPWD et PWD si ils n'existent pas
int				ft_exec_cd(char **env, char **cmd)
{
	char		*p;
	int			i;

	p = NULL;
	if (env && cmd && cmd[0])
		p = ft_contruct_path(env, cmd);
	i = -1;
	while (env && *p && ft_strcmp(env[++i], "\0"))
		if (!ft_strncmp(env[i], "OLDPWD", 5))
			env[i] = ft_strjoin("OLDPWD=", getcwd(NULL, 1024));
	if (access(p, F_OK) == 0 && access(p, R_OK) == 0 && access(p, X_OK) == 0)
	{
		chdir(p);
		i = -1;
		while (env && *p && ft_strcmp(env[++i], "\0"))
			if (!ft_strncmp(env[i], "PWD", 3))
				env[i] = ft_strjoin("PWD=", getcwd(NULL, 1024));
		//if (p && *p)
		//	ft_strdel(&p);
	}
	else
		return (ft_error("[exec_cmd] :", " no directory or authorization"));
	return (1);
}
