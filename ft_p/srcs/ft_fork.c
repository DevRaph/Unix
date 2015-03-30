/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 13:12:04 by rpinet            #+#    #+#             */
/*   Updated: 2015/03/30 13:12:06 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"

int				ft_fork_exec(int cs, char **cmd)
{
	int			status;
	pid_t		pid;

	(void)cs;
	(void)cmd;
	pid = fork();
	if (pid == 0)
	{
		// ft_builtin(cs, *cmd);
	}
	else if (pid < 0)
		ft_error("Fork", " fork failed\n");
	waitpid(pid, &status, 0);
	return (status);
}
