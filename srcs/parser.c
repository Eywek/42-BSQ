/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtouffet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 13:54:40 by vtouffet          #+#    #+#             */
/*   Updated: 2017/07/24 18:51:56 by vtouffet         ###   ########.fr       */
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

int	**read_file(int fd, int **map)
{
	ssize_t	bytes;
	char	buffer[BUFFER_SIZE];
	t_list	*node;
	char	*first_line;
	t_list	*current;
	int		i;
	int		newline_count;
	int		index;
	int		k;

	index = 1;
	newline_count = 0;
	while ((bytes = read(fd, &buffer, BUFFER_SIZE)))
	{
		k = 0;
		while (k++ < bytes) // on parcours ce qu'on a lu
		{
			if (buffer[k] == '\n')
				newline_count++;
			else if (newline_count == 1 && !first_line) // debut de la deuxieme ligne donc fin de la premiere
			{
				first_line = (char*)malloc(sizeof(char) * ft_list_size(node));
				current = node;
				i = 0;
				while (current)
				{
					first_line[i++] = current->data;
					current = current->next;
				}
				first_line[i] = '\0';
				i = 0;
				printf("Set config... (%s)\n", first_line);
				if (!(map = (int**)malloc(sizeof(int*) * ft_atoi(first_line)))) // on malloc la premiere dimension avec le atoi() de la premier ligne
					return (NULL);
				if (!(map[0] = (int*)malloc(sizeof(int*) * 4)))
					return (NULL);
				map[0][0] = first_line[ft_strlen(first_line) - 3];
				map[0][1] = first_line[ft_strlen(first_line) - 2];
				map[0][2] = first_line[ft_strlen(first_line) - 1];
				ft_list_clear(&node);
			}
			else if (newline_count == 0 || newline_count == 1) // premiere ligne
				ft_list_push_back(&node, buffer[k]);
			else if (newline_count == 2 && node) // fin de deuxieme ligne
			{
				if (!(map[index] = (int*)malloc(sizeof(int) * ft_list_size(node))))
					return (NULL);
				map[0][3] = ft_list_size(node); // set line size
				i = 0;
				printf("vide: %c\n", map[0][0]);
				printf("obstacle: %c\n", map[0][1]);
				printf("remplissage: %c\n", map[0][2]);
				printf("line size: %d\n", map[0][3]);
				current = node;
				while (current)
				{
					map[index][i++] = (current->data == map[0][0]) ? 1 : 0;
					printf("FIRST LINE map[%d][%d] = %d\n", index, i-1, map[index][i-1]);
					current = current->next;
				}
				i = 0;
				ft_list_clear(&node);
			}
			else if (newline_count > 2)
			{
				/*printf("vide: %c\n", map[0][0]);
				printf("obstacle: %c\n", map[0][1]);
				printf("line size: %d\n", map[0][3]);
				if (buffer[k] == '\n')
				{
					i = 0;
					if (!(map[++index] = (int*)malloc(sizeof(int) * 27)))
						return (NULL);
					printf("map[%d] = (int*)malloc(sizeof(int) * %d)\n", index, map[0][3]);
				}
				else
				{
					map[index][i++] = (buffer[k] == map[0][0]) ? 1 : 0;
					printf("map[%d][%d] = %d (%c)\n", index, i-1, map[index][i-1], buffer[k]);
				}*/
			}
		}
	}
	free(first_line);
	return (map);
}

/*
char	*linked_list_to_str(t_list **node)
{
	int		i;
	char	*str;
	t_list	*current;

	str = malloc(sizeof(char) * (ft_list_size(*node) + 1));
	current = *node;
	i = 0;
	while (current)
	{
		str[i++] = current->data;
		current = current->next;
	}
	str[i] = '\0';
	ft_list_clear(node);
	return (str);
}

char	*handle_file(char *filename)
{
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes;
	int		fd;
	t_list	*node;
	int		i;

	if (filename)
		fd = open(filename, O_RDONLY);
	else
		fd = 0;
	if (fd == -1)
	{
		write(2, "map error", 9);
		return (0);
	}
	while ((bytes = read(fd, &buffer, BUFFER_SIZE)))
	{
		i = 0;
		while (bytes-- > 0)
			ft_list_push_back(&node, buffer[i++]);
		//free(buffer);
	}
	//free(buffer);
	return (linked_list_to_str(&node));
}
*/
