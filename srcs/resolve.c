/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 19:16:39 by jechoque          #+#    #+#             */
/*   Updated: 2017/07/25 15:15:32 by vtouffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int	check_arround(int i, int j, int k)
{
	if (i <= j && i <= k)
		return (i);
	else if (j <= i && j <= k)
		return (j);
	else if (k <= i && k <= j)
		return (k);
	return (i);
}

int	**stock_coord(int **map, int x, int y)
{
	if (map[y][x] >= map[0][5])
	{
		map[0][5] = map[y][x];
		map[0][6] = x;
		map[0][7] = y;
	}
	return (map);
}

int	**resolve(int **map)
{
	int x;
	int y;

	x = 0;
	y = 1;
	//printf("%d != %d\n", map[0][4], map[0][8]);
	if (map == NULL || map[0][4] != map[0][8])
		return (NULL);
	map = stock_coord(map, x, y);
	y = (map[0][4]);
	while (y-- >= 1)
	{
		x = (map[0][3] - 2);
		while (x-- >= 0)
		{
			if (map[y][x] == 1)
			{
				map[y][x] = (1 + check_arround(map[y][x + 1], map[y + 1][x],
							map[y + 1][x + 1]));
				map = stock_coord(map, x, y);
				//display(map);
				//write(1, "\n\n", 2);
			}
		}
	}
	return (map);
}
