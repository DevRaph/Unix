/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 12:51:24 by rpinet            #+#    #+#             */
/*   Updated: 2015/03/30 12:52:45 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_P_H
# define FT_P_H

int					ft_fork(int cs, char **cmd);
void				ft_builtin(int cs, char **cmd);
void				ft_pwd(char **cmd);
int					ft_exec_cd(char **cmd);
void				ft_put(char **cmd);
void				ft_get(char **cmd);
void				ft_print_cmd(char **cmd);
char				*ft_clean(char *s);

#endif

