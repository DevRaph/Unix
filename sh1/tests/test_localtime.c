/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_localtime.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 17:00:07 by rpinet            #+#    #+#             */
/*   Updated: 2014/11/25 17:01:40 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>

int		main(void)
{
	time_t t;
	struct tm *heure;

	time(&t);
	heure = localtime(&t);
	printf ("Nombre de seconde écoulée depuis l'Epoch : %d\n", t);
	printf ("L'heure est donc : %dh%d:%d\n", heure->tm_hour, heure->tm_min, heure->tm_sec);
	printf ("La date est donc : %d/%d/%d\n", heure->tm_mday, heure->tm_mon, heure->tm_year);
	return (0);
}

