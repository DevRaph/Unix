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

int			ft_exec_cmd(char **env, char **cmd)
{
	int		status;
	pid_t	pid;
	char	**path;
	int		ok;

	while (*env++)
		if (!ft_strncmp(*(env - 1), "PATH", 4))
			path = ft_strsplit(*(env - 1) + 5, ':');
	pid = fork();
	if (pid == 0)
	{
		ok = 1;
		while (*path++)
			if (execve (ft_strjoin(ft_strjoin(*(path - 1), "/"), cmd[0]), cmd, env) != -1)
				ok = 0;
		if (ok == 1)
			ft_error("[exec_cmd] :", ft_strjoin(" command not found: ", cmd[0]));
		exit(0);
	}
	else if (pid < 0)
		ft_error("\n[exec_cmd] :", " : fork failed\n");
	waitpid(pid, &status, 0);
	return (status);
}

int			ft_exec(char **env, char **cmd)
{
	int		status;
	pid_t	pid;
	int		ok;

	pid = fork();
	if (pid == 0)
	{
		ok = 1;
		if ((execve (cmd[0], cmd, env)) != -1)
			ok = 0;
		if (ok == 1)
			ft_error("[exec_cmd] :", ft_strjoin(" command not found: ", cmd[0]));
		exit(0);
	}
	else if (pid < 0)
		ft_error("\n[exec_cmd] :", " : fork failed\n");
	waitpid(pid, &status, 0);
	return (status);
}
/*
   char		*ft_cd_reverse(char **env)
   {
   char	*tmp;

   tmp = ft_strdup(ft_get_env(env, "OLDPWD"));
//ft_setenv("OLDPWD", ft_get_env(env, "PWD") + 4, 1); // 1 pour overwrite ok pour reecriture dessus, 0 pour empecher
//ft_setenv("PWD", tmp + 7, 1);
return (tmp + 7);
}*/

static char		*ft_contruct_path(char **env, char **cmd)
{
	char	*path;

	path = NULL;
	if (!*(cmd + 1) || !ft_strncmp(*(cmd + 1), "~", 1))
	{
		path = ft_strdup(".");
		if (env != NULL || ft_get_env(env, "HOME") != NULL)
			path = ft_get_env(env, "HOME") + 5;
	}
	else if (!ft_strncmp(*(cmd + 1), "-", 1))
		path = ft_strdup(ft_get_env(env, "OLDPWD") + 7);//ft_cd_reverse(env);
	else if (!ft_strncmp(*(cmd + 1), "/", 1))
		path = ft_strdup(*(cmd + 1));
	else if (!ft_strncmp(*(cmd + 1), "./.", 3))
		path = ft_strdup(getcwd(NULL, 1024));
	else if (!ft_strncmp(*(cmd + 1), "./", 2))
		path = ft_strjoin(ft_strjoin(getcwd(NULL, 1024), "/"), *(cmd + 1)); //si pas env comportement indefini
	//path = ft_strjoin(ft_strjoin(ft_get_env(env, "PWD") + 4, "/"), *(cmd + 1));
	else
		path = ft_strjoin(ft_strjoin(getcwd(NULL, 1024), "/"), *(cmd + 1) + 2);
	//path = ft_strjoin(ft_strjoin(ft_get_env(env, "PWD") + 4, "/"), *(cmd + 1) + 2);
	return (path);
}

int			ft_exec_cd(char **env, char **cmd) // gerer le cd /path/to/dir
{
	char	*path;

	path = ft_contruct_path(env, cmd);
	while (env && *env)
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
		return(ft_error("[exec_cmd] :", " : no file or directory or not authorization"));
	//ft_strdel(&path);
	return (1);
}
