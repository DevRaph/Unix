/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_serveur.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 16:20:32 by rpinet            #+#    #+#             */
/*   Updated: 2015/03/30 12:54:02 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	ft_putstr("<addr> <port>\n");
	exit (-1);
}

int						create_client(char *addr, int port)
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
	sin.sin_addr.s_addr = inet_addr(addr);
	if (connect(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		ft_putstr("bind error\n");
		exit (2);
	}
	else
	{
		ft_putendl("client connected\n");
	}
	return (sock);
}

int						main(int ac, char **av)
{
	int					port;
	int					sock;
	int					ret;
	char				buf[1024];
	char				*str;

	if (ac != 3)
		usage(av[0]);
	port = atoi(av[2]);
	sock = create_client(av[1], port);
	ft_putstr("cl $> ");
	while ((ret = read(0, buf, 1023)) >= 0)
	{
		if (buf[0])
		{
			buf[ret] = '\0';
			str = getcwd(NULL, 1024);
			str = ft_strjoin(ft_strjoin(str, " "), buf);
			//send(3, str, ft_strlen(str), MSG_OOB);
			str = ft_clean(str);
			ft_putstr_fd(str, sock);
			if (!ft_strncmp(buf, "quit", 4))
				break ;
			ft_putstr("cl $> ");
		}
	}
	close (sock);
	return (0);
}
