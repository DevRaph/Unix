/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 20:42:30 by rpinet            #+#    #+#             */
/*   Updated: 2015/02/19 21:37:11 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_minishell1.h"

char			*ft_join(char *path, char *cmd)
{
	char		*ret;

	if (!path)
		return (".");
	ret = ft_strjoin(path, "/");
	ret = ft_strjoin(ret, cmd);
	return (ret);
}

int				ft_exec_cmd(char **env, char **cmd)
{
	int			status;
	pid_t		pid;
	char		**path;
	int			ok;

	path = NULL;
	while (env && *env)
		if (!ft_strncmp(*env++, "PATH", 4))
			path = ft_strsplit(*(env - 1) + 5, ':');
	//ft_print_tab(path);
	//ft_putendl("coucou");
	pid = fork();
	if (pid == 0)
	{
		ok = 1;
		while (path && *path)
			if (execve (ft_join(*path++, cmd[0]), cmd, env) != -1)
				ok = 0;
		if (ok == 1)
			ft_error("[exec_cmd]", ft_strjoin("command not found: ", cmd[0]));
		exit(0);
	}
	else if (pid < 0)
		ft_error("\n[exec_cmd] :", " : fork failed\n");
	waitpid(pid, &status, 0);
	return (status);
}

int				ft_exec(char **env, char **cmd)
{
	int			status;
	pid_t		pid;
	int			ok;
	char		*str;

	pid = fork();
	if (pid == 0 && cmd && cmd [0])
	{
		ok = 1;
		if (cmd && cmd[0] && (execve (cmd[0], cmd, env)) != -1)
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
	return (status);
}

static char		*ft_contruct_path(char **env, char **cmd)
{
	char		*path;

	path = NULL;
	if (!*(cmd + 1) || !ft_strncmp(*(cmd + 1), "~", 1))
	{
		path = ft_strdup(".");
		if (env != NULL || ft_get_env(env, "HOME") != NULL)
			path = ft_get_env(env, "HOME") + 5;
	}
	else if (!ft_strncmp(*(cmd + 1), "-", 1) && ft_get_env(env, "OLDPWD"))  // afficher chemin
		path = ft_strdup(ft_get_env(env, "OLDPWD") + 7);
	else if (!ft_strncmp(*(cmd + 1), "/", 1))
		path = ft_strdup(*(cmd + 1));
	else if (!ft_strncmp(*(cmd + 1), "./.", 3)) // amelioration
		path = ft_strdup(getcwd(NULL, 1024));
	else if (!ft_strncmp(*(cmd + 1), "./", 2))
		path = ft_join(getcwd(NULL, 1024), *(cmd + 1) + 2);
	else
		path = ft_join(getcwd(NULL, 1024), *(cmd + 1));
	return (path);
}

int				ft_exec_cd(char **env, char **cmd)
{
	char		*path;

	path = NULL;
	if (env && cmd && cmd[0])
		path = ft_contruct_path(env, cmd);
	while (env && *env && path) // verif le test && path
	{
		
		if (!ft_strncmp(*env, "PWD", 3))
			*env = ft_strjoin("PWD=", path);
		if (!ft_strncmp(*env, "OLDPWD", 3))
			*env = ft_strjoin("OLDPWD=", getcwd(NULL, 1024));
		env++;
	}
	if (access(path, F_OK) == 0 && access(path, R_OK) == 0)
		chdir(path);
	else
		return (ft_error("[exec_cmd] :", " no directory or authorization"));
	ft_strdel(&path);
	return (1);
}
