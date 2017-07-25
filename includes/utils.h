/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtouffet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 13:25:49 by vtouffet          #+#    #+#             */
/*   Updated: 2017/07/25 12:06:27 by vtouffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# define BUFFER_SIZE 28676

int		**handle_file(char *filename);
int		**read_file(int fd, int **map, int index, int *k);
int		ft_atoi(char *str);
int		ft_strlen(char *str);
int		**resolve(int **map);
void	display(int **map);
void	ft_putchar(char c);
int		**set_config(int **map, char *fline, int l_count, int length);
void	ft_putstr(char *str);
int		nb_size(int nb);

#endif
