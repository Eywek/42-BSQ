/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 19:52:41 by jechoque          #+#    #+#             */
/*   Updated: 2017/07/25 00:14:28 by jechoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_putnbr(int i);

void	display(int **tab);

int		**bsq_algo(int **tab);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(void)
{
	int **tab;
	int i;
	int j;

	i = 0;
	j = 0;
	tab = (int**)malloc(sizeof(int*) * 8);
	while (i < 8)
	{
		j = 0;
		tab[i] = (int*)malloc(sizeof(int) * 8);
		while (j < 8)
			tab[i][j++] = 1;
		i++;
	}
	tab[0][0] = 56;
	tab[0][1] = 58;
	tab[0][2] =	60;
	tab[0][3] = 8;
	tab[0][4] = 8;
	tab[0][5] = 0;
	tab[0][6] = 0;
	tab[1][2] = 0;
	tab[1][6] = 0;
	tab[3][7] = 0;
	tab[6][1] = 0;
	tab[2][2] = 0;
	tab = bsq_algo(tab);
	display(tab);
	/*while (i < 8)
	{
		j = -1;
		while (j++ < 8)
		{
			if (tab[i][j] == 0)
				ft_putchar(tab[0][1]);
			else if (j >= tab[0][6] && (j < tab[0][6] + tab[0][5]) && i >= tab[0][7] && i < (tab[0][7] + tab[0][5]))
				ft_putchar(tab[0][2]);
			else
				ft_putchar(tab[0][0]);
				ft_putchar(' ');
		}
		i++;
		ft_putchar('\n');
	}*/
	return (0);
}
