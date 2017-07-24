/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtouffet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 09:45:36 by vtouffet          #+#    #+#             */
/*   Updated: 2017/07/24 09:53:41 by vtouffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

char	**handle_file(char *filename)
{}

char	**handle_input()
{}

int main(int argc, char *argv[])
{
	if (argc > 1)
		while (argc-- > 0)
			resolve(handle_file(argv[argc]));
	else
		resolve(handle_input());
	return 0;
}
