/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dirent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 17:06:39 by rpinet            #+#    #+#             */
/*   Updated: 2015/02/10 17:06:41 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h" 
#include <dirent.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include <stdlib.h>
#include <stdio.h>


#define DOSSIER ./dossier
/*
typedef struct 				s_mydirent
{
}							t_mydirent
*/
int						ft_error(char *s, char *s2)
{
	write(1, "  ", 2);
	perror(s); // interdit

	if (s)
	{
		write(1, "  gestion erreur perso :\n  -->", 30);
		write(1, s, ft_strlen(s));
		if (s2)
			write(1, s2, ft_strlen(s2));
	}
	return (0);
}

char					*ft_file_type(struct stat *buf)
{
	if (buf->st_mode == 16877)
		return ("DOSSIER");
	else if (buf->st_mode == 33188)
		return ("FILE");
	else
		return (ft_itoa(buf->st_mode));
}

#include <time.h>
int						main(void)
{
	DIR					*rep;
	struct dirent		*replu;
	int					i;
	long				pos;
	struct dirent		*ent;
	struct stat			buf;
	int					ret;
	char				*path;



	rep = NULL;
	replu = NULL;
	printf ("Demarrage test\n");
	rep = opendir("./dossier2");
	if (rep == NULL)
		exit (ft_error("[Main] : ", "open failed"));
	printf ("dossier ouvert\n\n");
	i = 0;
	while ((replu = readdir(rep)) != NULL && i++ < 15)
	{
		path = ft_strjoin("./dossier2/", replu->d_name);
		printf("%s ", path);
		if ((ret = stat(path, &buf)) == -1)
			exit(ft_error("[ft_file_type] : ", "stat error"));
		printf ("[%s] ret=%d \n", ft_file_type(&buf), ret);
		//printf ("retour stat: %d\n", buf.st_size);
		printf ("atime[%d] st_mtime[%d] st_ctime[%d] creat at[%d]\n", buf.st_atime, buf.st_mtime, buf.st_ctime, buf.st_birthtime);
		printf("\t%ld ", telldir(rep));
		if (replu->d_name == "." || replu->d_name == "..")
			printf("dossier");
		else if (!ft_strchr(replu->d_name, '.'))
			printf("dossier");
		else
			printf("fichier");
		printf("   --> [%s]\n\n", replu->d_name);
		/*if (telldir(rep) == 3 && i < 10)
			rewinddir(rep);*/
	}
/*	printf ("\ntest de parcour\n");
	i = 0;
	while (i++ < 4)
		replu = readdir(rep);
	pos = telldir(rep);
	printf("pos:\t%ld --> %s\n", pos, replu->d_name);
	rewinddir(rep);
	printf("retour:\t%ld --> %s\n", telldir(rep), replu->d_name);
	seekdir(rep, pos);
	printf("saut:\t%ld --> %s\n", telldir(rep), replu->d_name);
	ent = readdir(rep);
	printf("suiv:\t%ld --> %s\n", telldir(rep), replu->d_name);
*/
	if (closedir(rep) == -1)
		exit (ft_error("[Main] : ", "close failed"));
	printf ("\ndossier ferme\n");
	return (0);
}
