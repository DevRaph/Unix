/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <rpinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 20:42:30 by rpinet            #+#    #+#             */
/*   Updated: 2015/03/20 18:38:48 by rpinet           ###   ########.fr       */
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
	while (path && *path++)
		if (execve (ft_join(*(path - 1), cmd[0]), cmd, environ) != -1)
			ok = 0;
	if (ok == 1)
		ft_error("exec_cmd", ft_strjoin("command not found: ", cmd[0]));
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
		if (!ft_strncmp(env[ok], "PATH=", 5))
			path = ft_strsplit(env[ok] + 5, ':');
	pid = fork();
	if (pid == 0)
	{
		ft_fork_cmd(path, cmd);
	}
	else if (pid < 0)
		ft_error("\nexec_cmd", " fork failed\n");
	waitpid(pid, &status, 0);
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

static char		**ft_rebuild(char **env, char *p, char *id)
{
	int			i;
	char		*str;

	i = 0;
	while (env && env[i] && *p && ft_strcmp(env[i++], "\0"))
	{
		str = ft_strjoin(id, "=");
		if (!ft_strncmp(env[i - 1], id, ft_strlen(id)))
			env[i - 1] = ft_strjoin(str, getcwd(NULL, 1024));
	}
	if (!ft_get_env(env, id) && !ft_strcmp(env[i - 1], "\0"))
	{
		str = ft_strjoin(id, "=");
		env[i - 1] = ft_strjoin(str, getcwd(NULL, 1024));
		env [i] = ft_strdup("\0");		
	}
//		ft_setenv("OLDPWD", getcwd(NULL, 1024), 1, env);
	return (env);
}

int				ft_exec_cd(char **env, char **cmd)
{
	char		*p;
//	int			i;

	p = NULL;
	if (env && cmd && cmd[0])
		p = ft_contruct_path(env, cmd);
	/*i = 0;
	while (env && env[i] && *p && ft_strcmp(env[i++], "\0"))
		if (!ft_strncmp(env[i - 1], "OLDPWD", 6))
			env[i - 1] = ft_strjoin("OLDPWD=", getcwd(NULL, 1024));
	if (!ft_get_env(env, "OLDPWD") && !ft_strcmp(env[i - 1], "\0"))
	{
		env[i - 1] = ft_strjoin("OLDPWD=", getcwd(NULL, 1024));
		env [i] = ft_strdup("\0");		
	}*/
	env = ft_rebuild(env, p, "OLDPWD");
	if (access(p, F_OK) == 0 && access(p, R_OK) == 0 && access(p, X_OK) == 0)
	{
		chdir(p);
	env = ft_rebuild(env, p, "PWD");
	/*	i = 0;
		while (env && env[i] && *p && ft_strcmp(env[i++], "\0"))
			if (!ft_strncmp(env[i - 1], "PWD", 3))
				env[i - 1] = ft_strjoin("PWD=", getcwd(NULL, 1024));
		if (!ft_get_env(env, "PWD") && !ft_strcmp(env[i - 1], "\0"))
		{
			env[i - 1] = ft_strjoin("PWD=", getcwd(NULL, 1024));
			env [i] = ft_strdup("\0");		
		}
//			ft_setenv("PWD", getcwd(NULL, 1024), 1, &env);*/
	}
	else
		return (ft_error("exec_cmd", "no directory or authorization"));
	return (1);
}
