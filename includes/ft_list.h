/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtouffet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 10:25:34 by vtouffet          #+#    #+#             */
/*   Updated: 2017/07/24 14:29:35 by vtouffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct	s_list
{
	char			data;
	struct s_list	*next;
}				t_list;

t_list			*ft_create_elem(char data);
void			ft_list_push_back(t_list **begin_list, char data);
int				ft_list_size(t_list *begin_list);
void			ft_list_clear(t_list **begin_list);

#endif
