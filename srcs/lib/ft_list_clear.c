/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtouffet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 12:56:03 by vtouffet          #+#    #+#             */
/*   Updated: 2017/07/24 14:29:56 by vtouffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/ft_list.h"

void	ft_list_clear(t_list **begin_list)
{
	t_list *to_free;

	if (!begin_list || !*begin_list)
		return ;
	while (*begin_list)
	{
		to_free = *begin_list;
		*begin_list = (*begin_list)->next;
		free(to_free);
	}
	*begin_list = NULL;
}
