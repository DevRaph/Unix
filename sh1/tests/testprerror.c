/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testprerror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 16:49:09 by rpinet            #+#    #+#             */
/*   Updated: 2014/11/25 16:49:59 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>

int		main(void)
{
	FILE *fichier = NULL;

	fichier = fopen ("fichier.txt", "r");
	if (fichier == NULL)
	{
		printf ("Code de l'erreur : %d\n", errno);
		perror("Erreur");
	}
	else
		fclose(fichier);
	return (0);
}

