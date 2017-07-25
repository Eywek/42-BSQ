/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 19:16:39 by jechoque          #+#    #+#             */
/*   Updated: 2017/07/25 01:42:36 by vtouffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_arround(int i, int j, int k)
{
	if (i <= j && i <= k)
		return (i);
	else if (j <= i && j <= k)
		return (j);
	return (k);
}

int	**resolve(int **map)
{
	int x;
	int y;

	y = (map[0][4] - 1);
	while (--y >= 1)
	{
		x = (map[0][3] - 1);
		while (x >= 0)
		{
			if (map[y][x] == 0)
				x--;
			else
			{
				map[y][x] = (1 + check_arround(map[y][x + 1], map[y + 1][x], map[y + 1][x + 1]));
				if (map[y][x] >= map[0][5])
				{
					map[0][5] = map[y][x];
					map[0][6] = x;
					map[0][7] = y;
				}
			}
			x--;
		}
	}
	return (map);
}
