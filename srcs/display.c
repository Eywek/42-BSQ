/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 20:47:23 by jechoque          #+#    #+#             */
/*   Updated: 2017/07/25 17:27:12 by vtouffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	display(int **map)
{
	int i;
	int j;

	i = 1;
	if (map == NULL)
	{
		ft_putstr("map error\n");
		return ;
	}
	while (i <= map[0][4])
	{
		j = -1;
		while (++j + 1 < map[0][3])
		{
			if (map[i][j] == 0)
				ft_putchar(map[0][1]);
			else if (j >= map[0][6] && (j < map[0][6] + map[0][5])
					&& i >= map[0][7] && i < (map[0][7] + map[0][5]))
				ft_putchar(map[0][2]);
			else
				ft_putchar(map[0][0]);
		}
		i++;
		ft_putchar('\n');
	}
}
