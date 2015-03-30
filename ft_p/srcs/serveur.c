/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_serveur.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 16:20:32 by rpinet            #+#    #+#             */
/*   Updated: 2015/03/30 13:01:20 by rpinet           ###   ########.fr       */
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
#include "../includes/ft_p.h"

void					usage(char *str)
{
	ft_putstr("usage : ");
	ft_putstr(str);
	ft_putstr(") <port>\n");
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
		ft_putendl("bind error\n");
		exit (2);
	}
	listen(sock, 42);
	return (sock);
}
/*
   void					ft_builtin(int cs, char *buf)
   {
   ft_putstr("[client - socket:");
   ft_putnbr(cs);
   ft_putstr("] $> ");
   ft_putendl(buf);
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
   }*/

void					ft_launch(int cs)
{
	int						ret;
	char					buf[1024];
	char					*str;
	char					**cmd;

	while ((ret = read (cs, buf, 1023)) > 0)
	{
		buf[ret] = '\0'; // segfault sur vide de temps en temps
		str = ft_clean(buf);
		cmd = ft_strsplit(buf, ' ');
		if (*(cmd + 1))
		{
			ft_putstr("[client - socket:");
			ft_putnbr(cs);
			ft_putstr("] >> ");
			//ft_print_tab(cmd++);
			ft_print_cmd(cmd);
			ft_builtin(cs, cmd);
			if (!ft_strncmp(*(cmd + 1), "quit", 4))
				break ;
		}
	}
}

void					ft_launch_socket(int sock)
{
	int						cs;
	unsigned int			cslen;
	struct sockaddr_in		*csin;
	//char					*receive;

	cs = accept(sock, (struct sockaddr *)&csin, &cslen);
	/*	receive = NULL;
		recv(cs, receive, ft_strlen(receive), MSG_OOB);
		ft_putstr("------> ");
		ft_putstr(receive);
		ft_putstr("\n");*/

	ft_launch(cs);
	close(cs);
}

int						main(int ac, char **av)
{
	int						port;
	int						sock;

	if (ac != 2)
		usage(av[0]);
	port = atoi(av[1]);
	sock = create_server(port);
	ft_putstr("\n   x-x open serveur | sock:");
	ft_putnbr(sock);
	ft_putendl(" x-x\n");
	while (1)
	{
		ft_launch_socket(sock);
	}
	close (sock);
	return (0);
}
