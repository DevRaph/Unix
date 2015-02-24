/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 18:51:49 by rpinet            #+#    #+#             */
/*   Updated: 2015/02/12 22:50:43 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_env			*ft_lstnew(t_env **env, char *str)
{
	t_env		*elem;
	char		*name;
	char		*path;
	char		**tab;

	if (!(elem = (t_env *)malloc(sizeof(t_env))))
		exit(ft_error("[lstnew] : ", ": malloc error"));
	if (env && *env)
	{
		tab = ft_strsplit(str, '=');
	}
	return (elem);
}
