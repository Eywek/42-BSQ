/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtouffet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 09:45:36 by vtouffet          #+#    #+#             */
/*   Updated: 2017/07/25 10:42:32 by vtouffet         ###   ########.fr       */
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

int	**set_config(int **map, char *fline, int l_count)
{
	int	length;

	length = ft_strlen(fline);
	map[0][0] = fline[length - 3];
	map[0][1] = fline[length - 2];
	map[0][2] = fline[length - 1];
	map[0][4] = l_count;
	printf("map[0][0] = %c;\n", map[0][0]);
	printf("map[0][1] = %c;\n", map[0][1]);
	printf("map[0][2] = %c;\n", map[0][2]);
	printf("map[0][4] = %d;\n", map[0][4]);
	return (map);
}
