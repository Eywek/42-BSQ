/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtouffet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 17:32:39 by vtouffet          #+#    #+#             */
/*   Updated: 2017/07/26 17:55:56 by vtouffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcut(char *str, int limit)
{
	int		length;
	int		count;
	char	*new;

	length = 0;
	while (str[length])
		++length;
	if (!(new = (char*)malloc(sizeof(char) * (length - limit))))
		return (0);
	count = -1;
	while (str[++count] && count < length - limit)
		new[count] = str[count];
	new[count] = '\0';
	return (new);
}
