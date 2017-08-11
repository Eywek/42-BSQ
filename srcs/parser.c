/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtouffet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 13:54:40 by vtouffet          #+#    #+#             */
/*   Updated: 2017/07/26 22:48:04 by vtouffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_list.h"
#include "../includes/utils.h"

int	**handle_file(char *filename)
{
	int		fd;
	int		k[4];
	int		**map;

	k[0] = 0;
	k[1] = 0;
	k[3] = 0;
	map = NULL;
	if (filename)
		fd = open(filename, O_RDONLY);
	else
		fd = 0;
	if (fd == -1)
		return (map);
	map = read_file(fd, map, 1, k);
	close(fd);
	return (map);
}

int	**save_first_line(t_list **node, int **map, int *first, int i)
{
	char	*fline;
	t_list	*current;
	int		l_count;
	int		length;

	if (!(fline = (char*)malloc(sizeof(char) * ft_list_size(*node))))
		return (NULL);
	current = *node;
	while (current && (fline[i++] = current->data))
		current = current->next;
	fline[i] = '\0';
	l_count = ft_atoi(ft_strcut(fline, 3));
	ft_list_clear(node);
	free(current);
	if ((length = ft_strlen(fline)) != nb_size(l_count) + 3)
		return (NULL);
	if (!(map = (int**)malloc(sizeof(int*) * (l_count + 2))))
		return (NULL);
	if (!(map[0] = (int*)malloc(sizeof(int) * 9)))
		return (NULL);
	map = set_config(map, fline, l_count, length);
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
	map[0][3] = node_size;
	map[0][5] = 0;
	i = 0;
	current = *node;
	while (current)
	{
		if (current->data != map[0][0] && current->data != map[0][1])
			return (NULL);
		map[index][i++] = (current->data == map[0][0]) ? 1 : 0;
		current = current->next;
	}
	i = 0;
	ft_list_clear(node);
	return (map);
}

int	**save_lines(int **map, int *index, char c, int *i)
{
	if (*i > map[0][3])
		return (NULL);
	if (c == '\n')
	{
		++(*index);
		if (*index > 2 && *i < map[0][3])
			return (NULL);
		*i = 0;
		if (!(map[*index] = (int*)malloc(sizeof(int) * (map[0][3]))))
			return (NULL);
	}
	else if (c)
	{
		if (c != map[0][0] && c != map[0][1])
			return (NULL);
		map[*index][(*i)++] = (c == map[0][0]) ? 1 : 0;
	}
	return (map);
}

int	**read_file(int fd, int **map, int index, int *k)
{
	ssize_t	bytes;
	char	buffer[BUFFER_SIZE];
	t_list	*node;

	while ((bytes = read(fd, &buffer, BUFFER_SIZE)))
	{
		k[2] = -1;
		while ((++k[2]) < bytes)
		{
			if (buffer[k[2]] == '\n')
				k[0]++;
			if (k[0] == 1 && k[1] == 0)
				map = save_first_line(&node, map, &k[1], 0);
			else if (k[0] == 0 || k[0] == 1)
				ft_list_push_back(&node, buffer[k[2]]);
			else if (k[0] == 2 && node)
				map = save_second_line(&node, map, 1);
			if (k[0] >= 2 && map != NULL)
				map = save_lines(map, &index, buffer[k[2]], &k[3]);
			if (map == NULL && k[0] >= 1)
				return (NULL);
			buffer[k[2]] = '\0';
		}
	}
	return ((map[0][8] = --index) ? map : map);
}
