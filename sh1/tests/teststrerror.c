/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teststrerror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 15:31:37 by rpinet            #+#    #+#             */
/*   Updated: 2014/11/25 15:33:51 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(void)
{
	FILE *fichier = NULL;

	fichier = fopen ("fichier.txt", "r");
	if (fichier == NULL) {
		printf ("Code de l'erreur : %d\n", errno);
		printf ("La signification de l'erreur est donc : %s\n", strerror(errno));
	}
	else
		fclose(fichier);
	return (0);
}
