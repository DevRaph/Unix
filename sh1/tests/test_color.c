/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 17:02:53 by rpinet            #+#    #+#             */
/*   Updated: 2014/11/25 17:04:05 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

enum {NOIR = 30, ROUGE, VERT, JAUNE, BLEU, MAGENTA, CYAN, BLANC};

void	ColorAllShell(int C_texte, int C_fond)
{
	printf ("\033[%d;%dmn", C_texte, C_fond + 10);
	system("clear");
}

void	WriteInColor(char texte[], int C_texte, int C_fond, int init)
{
	if (init)
		printf ("\033[%d;%dm%s\033[0m\n", C_texte, C_fond + 10, texte);
	else
		printf ("\033[%d;%dm%s\n", C_texte, C_fond + 10, texte);
}

int		main(void)
{
	ColorAllShell(ROUGE, VERT);
	WriteInColor("Salut", ROUGE, BLANC, 1);
	return (0);
}
