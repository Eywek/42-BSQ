/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtouffet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 09:45:36 by vtouffet          #+#    #+#             */
/*   Updated: 2017/07/25 12:14:12 by vtouffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int	main(int argc, char *argv[])
{
	int	count;

	count = 0;
	if (argc > 1)
		while (++count < argc)
		{
			display(resolve(handle_file(argv[count])));
			if (count + 1 < argc)
				ft_putchar('\n');
		}
	else
		display(resolve(handle_file(0)));
	return (0);
}

int	**set_config(int **map, char *fline, int l_count, int length)
{
	map[0][0] = fline[length - 3];
	map[0][1] = fline[length - 2];
	map[0][2] = fline[length - 1];
	map[0][4] = l_count;
	return (map);
}

int	nb_size(int nb)
{
	int	count;

	count = 1;
	while (nb >= 10)
	{
		nb /= 10;
		++count;
	}
	return (count);
}
