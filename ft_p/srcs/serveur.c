/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_serveur.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 16:20:32 by rpinet            #+#    #+#             */
/*   Updated: 2015/03/26 14:03:14 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "../libft/libft.h"

void					usage(char *str)
{
	printf("usage : %s <port>\n", str);
	exit (-1);
}

int						create_server(int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;

	proto = getprotobyname("tcp");
	if (!proto)
		return (-1);
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		printf ("bind error\n");
		exit (2);
	}
	listen(sock, 42);
	return (sock);
}

void					ft_builtin(int cs, char *buf)
{
	printf ("client %d -> %s", cs, buf);
	if (!ft_strncmp(buf, "ls", 2))
		ft_putendl("execv ls");
	else if (!ft_strncmp(buf, "cd", 2))
		ft_putendl("execv cd");
	else if (!ft_strncmp(buf, "pwd", 3))
		ft_putendl("execv pwd");
	else if (!ft_strncmp(buf, "put", 3))
	{
		ft_putendl("execv put");
	}
	else if (!ft_strncmp(buf, "get", 3))
	{
		ft_putendl("execv get");
	}
	else if (!ft_strncmp(buf, "quit", 2))
		ft_putendl("deconnexion du client");
	else
		ft_putendl("command not found");
}

int						main(int ac, char **av)
{
	int						port;
	int						sock;
	int						cs;
	unsigned int			cslen;
	struct sockaddr_in		*csin;
	int						ret;
	char					buf[1024];

	if (ac != 2)
		usage(av[0]);
	port = atoi(av[1]);
	sock = create_server(port);
	cs = accept(sock, (struct sockaddr *)&csin, &cslen);
	while ((ret = read (cs, buf, 1023)) > 0)
	{
		buf[ret] = '\0';
		//if (ft_strncmp(buf, "exit", 4))
			ft_builtin(cs, buf);
		/*else
		{
			ft_putendl("--> client disconnected");
			break ;
		}*/
	}
	close(cs);
	close (sock);
	return (0);
}
