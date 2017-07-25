/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtouffet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 13:54:40 by vtouffet          #+#    #+#             */
/*   Updated: 2017/07/25 01:51:11 by vtouffet         ###   ########.fr       */
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
	return (read_file(fd, map, 1, 0));
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
	if (!(map = (int**)malloc(sizeof(int*) * ((l_count = ft_atoi(fline)) + 2))))
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
	return (map);
}

int	**save_second_line(t_list **node, int **map, int index)
{
	t_list	*current;
	int		i;
	int		node_size;

	node_size = ft_list_size(*node);
	if (!(map[index] = (int*)malloc(sizeof(int) * (node_size))))
		return (NULL);
	map[0][3] = node_size + 1;
	i = 0;
	current = *node;
	while (current)
	{
		map[index][i++] = (current->data == map[0][0]) ? 1 : 0;
		current = current->next;
	}
	i = 0;
	ft_list_clear(node);
	return (map);
}

int	**save_lines(int **map, int *index, char c, int *i)
{
	if (c == '\n')
	{
		++(*index);
		*i = 0;
		if (!(map[*index] = (int*)malloc(sizeof(int) * (map[0][3]))))
			return (NULL);
	}
	else if (c)
		map[*index][(*i)++] = (c == map[0][0]) ? 1 : 0;
	return (map);
}

int	**read_file(int fd, int **map, int index, int i)
{
	ssize_t	bytes;
	char	buffer[BUFFER_SIZE];
	t_list	*node;
	int		k[3];

	k[1] = 0;
	k[0] = 0;
	while ((bytes = read(fd, &buffer, BUFFER_SIZE)) && (k[2] = -1))
	{
		while ((k[2]++) < bytes)
		{
			if (buffer[k[2]] == '\n')
				k[0]++;
			if (k[0] == 1 && k[1] == 0)
				map = save_first_line(&node, map, &k[1]);
			else if (k[0] == 0 || k[0] == 1)
				ft_list_push_back(&node, buffer[k[2]]);
			else if (k[0] == 2 && node)
				map = save_second_line(&node, map, 1);
			if (k[0] >= 2 && (buffer[k[2]] != '\n' || (buffer[k[2]] == '\n'
							&& buffer[k[2] + 1])))
				map = save_lines(map, &index, buffer[k[2]], &i);
		}
	}
	printf("map[0][0] = %c\n", map[0][0]);
	printf("map[0][1] = %c\n", map[0][1]);
	printf("map[0][2] = %c\n", map[0][2]);
	printf("map[0][3] = %d\n", map[0][3]);
	printf("map[0][4] = %d\n", map[0][4]);
	return (map);
}
