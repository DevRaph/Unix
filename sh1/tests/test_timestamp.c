/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_timestamp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 16:55:34 by rpinet            #+#    #+#             */
/*   Updated: 2014/11/25 16:56:19 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>

int		main(void)
{
	time_t t;
	time(&t);
	printf ("Nombre de seconde écoulée depuis l'Epoch : %d\n", t);
	return (0);
}
