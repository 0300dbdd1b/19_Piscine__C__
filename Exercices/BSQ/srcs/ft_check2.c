/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:45:08 by escarrie          #+#    #+#             */
/*   Updated: 2019/11/19 11:46:38 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_bsq.h"

int		ft_check_empty_line(char *str)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			nb++;
		else
			nb = 0;
		if (nb > 1)
			return (1);
		i++;
	}
	return (0);
}

int		ft_check_board(t_map *map)
{
	int i;
	int j;

	i = 1;
	while (map->board[i])
	{
		j = 0;
		while (map->board[i][j])
		{
			if (map->board[i][j] != map->s[0] && map->board[i][j] != map->s[1])
			{
				ft_putstr_error("map error\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
