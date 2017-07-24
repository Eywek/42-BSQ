/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 20:47:23 by jechoque          #+#    #+#             */
/*   Updated: 2017/07/25 00:15:17 by jechoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	display(int **tab)
{
	int i;
	int j;

	i = 1;
	while (i < 8)
	{
		j = -1;
		while (j++ < 8)
		{
			if (tab[i][j] == 0)
				ft_putchar(tab[0][1]);
			else if (j >= tab[0][6] && (j < tab[0][6] + tab[0][5]) 
					&& i >= tab[0][7] && i < (tab[0][7] + tab[0][5]))
				ft_putchar(tab[0][2]);
			else
				ft_putchar(tab[0][0]);
			ft_putchar(' ');
		}
		i++;
		ft_putchar('\n');
	}
}
