/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 19:16:39 by jechoque          #+#    #+#             */
/*   Updated: 2017/07/25 00:16:39 by jechoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putnbr(int i);

int		check_arround(int i, int j, int k)
{
	if (i <= j && i <= k)
		return (i);
	else if (j <= i && j <= k)
		return (j);
	return (k);
}

int		**bsq_algo(int **tab)
{
	int x;
	int y;

	y = (tab[0][4] - 1);
	while (--y >= 1)
	{
		x = (tab[0][3] - 1);
		while (x >= 0)
		{
			if (tab[y][x] == 0)
				x--;
			else
			{
				tab[y][x] = (1 + check_arround(tab[y][x + 1], tab[y + 1][x], tab[y + 1][x + 1]));
				if (tab[y][x] >= tab[0][5])
				{
					tab[0][5] = tab[y][x];
					tab[0][6] = x;
					tab[0][7] = y;
				}
			}
			x--;
		}
	}
	return (tab);
}
