/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell1.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 16:20:19 by rpinet            #+#    #+#             */
/*   Updated: 2015/02/10 16:21:19 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL1_H
# define FT_MINISHELL1_H

//#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct 			s_env
{
		char			*name;
		char			*path;
		struct s_env	*next;
}						t_env;

char		*ft_clean(char *s);
int			ft_minishell1(char **av, char **env);
char		**ft_builtin(char **env, char **cmd);
char		*ft_clean(char *s);
char		*ft_get_env(char **env, char *id);
void		ft_print_cmd(char **cmd);
void		ft_env(char **env, char **cmd);
char		**ft_unsetenv(const char *name, char **env);
char		**ft_setenv(const char *name, const char *value, int o, char **env);
int			ft_size_tab(char **env);
int			ft_exec_cmd(char **env, char **cmd);
int			ft_exec(char **env, char **cmd);
int			ft_exec_cd(char **env, char **cmd);

#endif
