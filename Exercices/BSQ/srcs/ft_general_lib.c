/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_general_lib.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:48:42 by naddino           #+#    #+#             */
/*   Updated: 2019/11/20 12:18:21 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_bsq.h"

void	ft_free_all(t_map *map)
{
	free(map->board);
	free(map->s);
}

void	ft_putstr_error(char *str)
{
	int x;

	x = 0;
	while (str[x])
		write(2, &str[x++], 1);
}

void	ft_putstr(char *str)
{
	int x;

	x = 0;
	while (str[x])
	{
		write(1, &str[x], 1);
		x++;
	}
}

int		ft_strlen(char *str)
{
	int x;

	x = 0;
	while (str[x])
		x++;
	return (x);
}

int		ft_get_max_y(char **board)
{
	int x;

	x = 0;
	while (board[x])
		x++;
	return (x);
}
