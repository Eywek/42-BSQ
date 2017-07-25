/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtouffet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 09:45:36 by vtouffet          #+#    #+#             */
/*   Updated: 2017/07/25 12:07:15 by vtouffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int	main(int argc, char *argv[])
{
	if (argc > 1)
		while (--argc > 0)
		{
			display(resolve(handle_file(argv[argc])));
			if (argc - 1 > 0)
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
