/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <rpinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 20:42:30 by rpinet            #+#    #+#             */
/*   Updated: 2015/03/19 21:10:07 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_minishell1.h"

static void		ft_fork_cmd(char **path, char **cmd)
{
	int			ok;

	extern char	**environ;

	if (cmd == NULL || cmd[0] == NULL || !ft_strcmp(cmd[0], ""))
		exit (0);
	ok = 1;
	while (path && *path)
		if (execve (ft_join(*path++, cmd[0]), cmd, environ) != -1)
			ok = 0; // path pas del avant de quitter
	if (ok == 1)
		ft_error("[exec_cmd]", ft_strjoin("command not found: ", cmd[0]));
	exit(0);
}

int				ft_exec_cmd(char **env, char **cmd)
{
	int			status;
	pid_t		pid;
	char		**path;
	int			ok;

	path = NULL;
	ok = -1;
	while (env && *env && ft_strcmp(env[++ok], "\0"))
		if (!ft_strncmp(env[ok], "PATH", 4))
			path = ft_strsplit(env[ok] + 5, ':');
	pid = fork();
	if (pid == 0)
	{
		ft_fork_cmd(path, cmd);
	}
	else if (pid < 0)
		ft_error("\n[exec_cmd] :", " : fork failed\n");
	waitpid(pid, &status, 0);
	//ft_strdel(path);
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
			ft_strdel(&str);
		}
		exit(0);
	}
	else if (pid < 0)
		ft_error("\n[exec_cmd] :", " : fork failed\n");
	waitpid(pid, &status, 0);
	(void)env;
	return (status);
}

static char		*ft_contruct_path(char **env, char **cmd)
{
	char		*path;
	char		*str;

	str = getcwd(NULL, 1024);
	if (!*(cmd + 1) || (!ft_strncmp(*(cmd + 1), "~", 1) && !*(cmd + 2)))
	{
		path = str;
		if (env && ft_get_env(env, "HOME"))
			path = ft_get_env(env, "HOME") + 5;
	}
	else if ((*(cmd + 1)[0] == '-') && ft_get_env(env, "OLDPWD"))
	{
		path = ft_strdup(ft_get_env(env, "OLDPWD") + 7);
		ft_putendl(str);
	}
	else if (!ft_strncmp(*(cmd + 1), "/", 1))
		path = ft_strdup(*(cmd + 1));
	else
		path = ft_join(str, *(cmd + 1));
	return (path);
}

int				ft_exec_cd(char ***env, char **cmd)
{
	char		*p;
	int			i;

	p = NULL;
	if (*env && cmd && cmd[0])
		p = ft_contruct_path(*env, cmd);
	i = 0;
	while (env && *env && *p && !ft_strcmp(*env[i++], "\0"))
		if (!ft_strncmp(*env[i - 1], "OLDPWD", 6))
			*env[i - 1] = ft_strjoin("OLDPWD=", getcwd(NULL, 1024));
	ft_putendl("coucou");
	if (*env && ft_get_env(*env, "OLDPWD") == NULL && !ft_strcmp(*env[i - 1], "\0"))
		ft_setenv("OLDPWD", getcwd(NULL, 1024), 1, env);
//		*env[i] = ft_strjoin("OLDPWD=", getcwd(NULL, 1024));
	if (access(p, F_OK) == 0 && access(p, R_OK) == 0 && access(p, X_OK) == 0)
	{
		chdir(p);
		//i = -1;
		//while (env && *env && *env[++i] && ft_strcmp(*env[i], "\0"))
		i = 0;
		while (env && *env && *env[i] && !ft_strcmp(*env[i++], "\0"))
			if (!ft_strncmp(*env[i - 1], "PWD", 3))
				*env[i - 1] = ft_strjoin("PWD=", getcwd(NULL, 1024));
		if (env && *env && ft_get_env(*env, "PWD") == NULL && !ft_strcmp(*env[i - 1], "\0"))
			ft_setenv("PWD", getcwd(NULL, 1024), 1, env);
	//		*env[i] = ft_strjoin("PWD=", getcwd(NULL, 1024));
	}
	else
		return (ft_error("[exec_cmd] :", " no directory or authorization"));
	return (1);
}
