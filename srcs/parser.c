/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtouffet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 13:54:40 by vtouffet          #+#    #+#             */
/*   Updated: 2017/07/24 23:26:07 by vtouffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_list.h"
#include "../includes/utils.h"

int	**handle_file(char *filename)
{
	int		fd;
	int		i;
	int		**map;

	if (filename)
		fd = open(filename, O_RDONLY);
	else
		fd = 0;
	if (fd == -1)
		return (map);
	return (read_file(fd, map));
}

int	**save_first_line(t_list **node, int **map, int *first)
{
	int		i;
	char	*fline;
	t_list	*current;
	int		length;
	int		l_count;

	fline = (char*)malloc(sizeof(char) * ft_list_size(*node));
	current = *node;
	i = 0;
	while (current && (fline[i++] = current->data))
		current = current->next;
	fline[i] = '\0';
	i = 0;
	if (!(map = (int**)malloc(sizeof(int*) * ((l_count = ft_atoi(fline)) + 2)))) // on malloc la premiere dimension avec le atoi() de la premier ligne
		return (NULL);
	if (!(map[0] = (int*)malloc(sizeof(int) * 7)))
		return (NULL);
	map[0][0] = fline[(length = ft_strlen(fline)) - 3];
	map[0][1] = fline[length - 2];
	map[0][2] = fline[length - 1];
	map[0][4] = l_count;
	ft_list_clear(node);
	free(fline);
	*first = 1;
	printf("Set config... (%s) - line_count: %d - length: %d\n", fline, l_count, length);
	return (map);
}

int	**save_second_line(t_list **node, int **map, int index)
{
	t_list	*current;
	int		i;
	int		node_size;

	node_size = ft_list_size(*node);
	printf("- map[%d] = (int*)malloc(sizeof(int) * %d);\n", index, node_size);
	if (!(map[index] = (int*)malloc(sizeof(int) * (node_size))))
		return (NULL);
	map[0][3] = node_size + 1; // set line size
	i = 0;
	printf("vide: %c\n", map[0][0]);
	printf("obstacle: %c\n", map[0][1]);
	printf("remplissage: %c\n", map[0][2]);
	printf("line size: %d\n", map[0][3]);
	printf("map size: %d\n", map[0][4]);
	current = *node;
	while (current)
	{
		map[index][i++] = (current->data == map[0][0]) ? 1 : 0;
		printf("FIRST LINE map[%d][%d] = %d\n", index, i-1, map[index][i-1]);
		current = current->next;
	}
	i = 0;
	ft_list_clear(node);
	return (map);
}

int	**save_lines(int **map, int *index, char c, int *i, int k)
{
	if (c == '\n')
	{
		++(*index);
		*i = 0;
		printf("_ map[%d] = (int*)malloc(sizeof(int) * %d);\n", *index, map[0][3]);
		if (!(map[*index] = (int*)malloc(sizeof(int) * (map[0][3]))))
			return (NULL);
	}
	else if (c)
	{
		map[*index][(*i)++] = (c == map[0][0]) ? 1 : 0;
		printf("map[%d][%d] = %d\n", *index, *i-1, map[*index][*i -1]);
	}
	return (map);
}

int	**read_file(int fd, int **map)
{
	ssize_t	bytes;
	char	buffer[BUFFER_SIZE];
	t_list	*node;
	int		newline_count;
	int		index;
	int		k;
	int		first;
	int		i;

	index = 1;
	first = 0;
	i = 0;
	newline_count = 0;
	while ((bytes = read(fd, &buffer, BUFFER_SIZE)))
	{
		k = -1;
		while (k++ < bytes) // on parcours ce qu'on a lu
		{
			if (buffer[k] == '\n')
				newline_count++;
			if (newline_count == 1 && first == 0) // debut de la deuxieme ligne donc fin de la premiere
				map = save_first_line(&node, map, &first);
			else if (newline_count == 0 || newline_count == 1) // premiere ligne
				ft_list_push_back(&node, buffer[k]);
			else if (newline_count == 2 && node) // fin de deuxieme ligne
				map = save_second_line(&node, map, 1);
			if (newline_count >= 2 && (buffer[k] != '\n' || (buffer[k] == '\n' && buffer[k + 1]))) // autres lignes
				map = save_lines(map, &index, buffer[k], &i, k);
		}
	}
	return (map);
}
